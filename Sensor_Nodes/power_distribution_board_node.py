import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32

import board
import busio
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn


class PDBMonitorNode(Node):
    def __init__(self):
        super().__init__('pdb_monitor_node')
        self.get_logger().info("🔌 Initializing Power Distribution Board Monitor Node...")

        try:
            # Setup I2C and ADC
            i2c = busio.I2C(board.SCL, board.SDA)
            self.ads = ADS.ADS1115(i2c)
            self.ads.gain = 1  # ±4.096V

            # Setup ADC channels
            self.battery = AnalogIn(self.ads, ADS.P0)
            self.solar = AnalogIn(self.ads, ADS.P1)
            self.output = AnalogIn(self.ads, ADS.P2)
            self.solar_current = AnalogIn(self.ads, ADS.P3)

        except Exception as e:
            self.get_logger().error(f"❌ ADS1115 initialization failed: {e}")
            rclpy.shutdown()
            return

        # Publishers for each parameter
        self.batt_pub = self.create_publisher(Float32, '/pdb/battery_voltage', 10)
        self.solar_pub = self.create_publisher(Float32, '/pdb/solar_voltage', 10)
        self.out_pub = self.create_publisher(Float32, '/pdb/output_voltage', 10)
        self.curr_pub = self.create_publisher(Float32, '/pdb/solar_current', 10)

        # Timer to publish at 1Hz
        self.timer = self.create_timer(1.0, self.publish_readings)
        self.get_logger().info("✅ PDB Monitor Ready!")

    def publish_readings(self):
        try:
            # Apply voltage divider ratio (e.g., 5:1)
            battery_v = round(self.battery.voltage * 5.0, 2)
            solar_v = round(self.solar.voltage * 5.0, 2)
            output_v = round(self.output.voltage * 5.0, 2)

            # ACS712: 2.5V at 0A, 185mV per A (for 5A version)
            raw_current = self.solar_current.voltage
            current_a = round((raw_current - 2.5) / 0.185, 2)

            # Publish to topics
            self.batt_pub.publish(Float32(data=battery_v))
            self.solar_pub.publish(Float32(data=solar_v))
            self.out_pub.publish(Float32(data=output_v))
            self.curr_pub.publish(Float32(data=current_a))

            # Optional: Comment this in final deployment to avoid log spam
            self.get_logger().info(f"🔋 Batt: {battery_v}V | ☀️ Solar: {solar_v}V | ⚡ Out: {output_v}V | 🔌 Curr: {current_a}A")

        except Exception as e:
            self.get_logger().warn(f"⚠️ Sensor Read Error: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = PDBMonitorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
