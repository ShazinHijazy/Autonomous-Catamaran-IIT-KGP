import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix, NavSatStatus
import smbus2
import pynmea2

class GNSSNode(Node):
    def _init_(self):
        super()._init_('gnss_node')

        self.publisher_ = self.create_publisher(NavSatFix, 'fix', 10)

        # ✅ I2C Configuration
        self.i2c_bus_number = 1
        self.i2c_address = 0x66  # Your GNSS module's I2C address

        try:
            self.bus = smbus2.SMBus(self.i2c_bus_number)
            self.get_logger().info(f'✅ GNSS connected on I2C address 0x{self.i2c_address:02X}')
        except Exception as e:
            self.get_logger().error(f'❌ I2C bus open failed: {e}')
            rclpy.shutdown()
            return

        # 🔁 Timer-based polling (10 Hz)
        self.timer = self.create_timer(0.1, self.read_gnss)

    def read_gnss(self):
        try:
            # 🧠 Read data from I2C device
            raw_data = self.bus.read_i2c_block_data(self.i2c_address, 0x00, 64)
            nmea_sentence = bytes(raw_data).decode('ascii', errors='ignore').strip()

            for line in nmea_sentence.splitlines():
                if line.startswith('$GPGGA') or line.startswith('$GNGGA'):
                    try:
                        msg = pynmea2.parse(line)
                        navsat_msg = NavSatFix()
                        navsat_msg.header.stamp = self.get_clock().now().to_msg()
                        navsat_msg.header.frame_id = 'gnss_link'

                        # 🌐 Coordinates and altitude
                        navsat_msg.latitude = float(msg.latitude)
                        navsat_msg.longitude = float(msg.longitude)
                        navsat_msg.altitude = float(msg.altitude)

                        # 📡 Status
                        gps_qual = int(msg.gps_qual) if msg.gps_qual.isdigit() else 0
                        navsat_msg.status.status = (
                            NavSatStatus.STATUS_FIX if gps_qual > 0 else NavSatStatus.STATUS_NO_FIX
                        )
                        navsat_msg.status.service = NavSatStatus.SERVICE_GPS

                        self.publisher_.publish(navsat_msg)

                        self.get_logger().info(
                            f'📍 GNSS Fix: Lat={navsat_msg.latitude:.6f}, Lon={navsat_msg.longitude:.6f}, Alt={navsat_msg.altitude:.2f}m'
                        )
                    except pynmea2.ParseError as e:
                        self.get_logger().warn(f'⚠ NMEA parse error: {e}')
        except UnicodeDecodeError as e:
            self.get_logger().warn(f'⚠ Unicode decode error: {e}')
        except OSError as e:
            self.get_logger().error(f'❌ I2C read failed: {e}')
        except Exception as e:
            self.get_logger().error(f'❌ Unexpected GNSS error: {e}')

    def destroy_node(self):
        try:
            if hasattr(self, 'bus'):
                self.bus.close()
                self.get_logger().info('✅ I2C bus closed')
        except Exception as e:
            self.get_logger().warn(f'⚠ Failed to close I2C bus: {e}')
        finally:
            super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = GNSSNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if _name_ == '_main_':
    main()