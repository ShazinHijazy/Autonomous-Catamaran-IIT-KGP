import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix, NavSatStatus
import serial
import pynmea2

class GNSSNode(Node):
    def __init__(self):
        super().__init__('gnss_node')

        # Publisher to /fix topic
        self.publisher_ = self.create_publisher(NavSatFix, 'fix', 10)

        # Define serial port (update as needed)
        self.port = '/dev/ttyUSB0'  # Could be /dev/ttyAMA0 or COMx on Windows
        self.baudrate = 9600

        try:
            self.serial_port = serial.Serial(self.port, baudrate=self.baudrate, timeout=1)
            self.get_logger().info(f'✅ GNSS connected on {self.port}')
        except Exception as e:
            self.get_logger().error(f'❌ Could not open serial port: {e}')
            rclpy.shutdown()
            return

        # Timer to check serial data (10Hz)
        self.timer = self.create_timer(0.1, self.read_gnss)

    def read_gnss(self):
        try:
            line = self.serial_port.readline().decode('ascii', errors='replace').strip()

            if line.startswith('$GPGGA') or line.startswith('$GNGGA'):
                msg = pynmea2.parse(line)

                # Construct ROS message
                navsat_msg = NavSatFix()
                navsat_msg.header.stamp = self.get_clock().now().to_msg()
                navsat_msg.header.frame_id = 'gnss_link'

                navsat_msg.latitude = float(msg.latitude)
                navsat_msg.longitude = float(msg.longitude)
                navsat_msg.altitude = float(msg.altitude)

                gps_qual = int(msg.gps_qual) if msg.gps_qual.isdigit() else 0
                navsat_msg.status.status = (
                    NavSatStatus.STATUS_FIX if gps_qual > 0 else NavSatStatus.STATUS_NO_FIX
                )
                navsat_msg.status.service = NavSatStatus.SERVICE_GPS

                self.publisher_.publish(navsat_msg)
                self.get_logger().info(
                    f'📍 GPS: {navsat_msg.latitude:.6f}, {navsat_msg.longitude:.6f}, Alt: {navsat_msg.altitude:.2f} m')

        except pynmea2.ParseError as e:
            self.get_logger().warn(f'⚠️ Parse error: {e}')
        except Exception as e:
            self.get_logger().error(f'❌ Error reading GNSS: {e}')

def main(args=None):
    rclpy.init(args=args)
    node = GNSSNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if hasattr(node, 'serial_port'):
            node.serial_port.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
