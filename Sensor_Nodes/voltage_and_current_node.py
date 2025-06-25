import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32

import board
import busio
import adafruit_ads1x15.ads1115 as ADS
from adafruit_ads1x15.analog_in import AnalogIn

class SensorMonitorNode(Node):
    def __init__(self):
        super().__init__('sensor_monitor_node')

        self.get_logger().info("🔌 Initializing Voltage & Current Monitor Node...")

        try:
            # I2C bus and ADC init
            i2c = busio.I2C(board.SCL, board.SDA)
            self.ads = ADS.ADS1115(i2c)

            # Set gain if needed (default 1 = ±4.096V)
            self.ads.gain = 1

            # ADC channels: Voltage on A0, Current on A1
            self.voltage_channel = AnalogIn(self.ads, ADS.P0)
            self.current_channel = AnalogIn(self.ads, ADS.P1)

        except Exception as e:
            self.get_logger().error(f"❌ Failed to initialize ADC: {e}")
            rclpy.shutdown()
            return

        # Create ROS 2 publishers
        self.voltage_pub = self.create_publisher(Float32, '/power/voltage', 10)
        self.current_pub = self.create_publisher(Float32, '/power/current', 10)

        # Set read frequency (0.5 seconds)
        self.timer = self.create_timer(0.5, self.read_and_publish)

        self.get_logger().info("✅ Sensor Monitor Node Ready")

    def read_and_publish(self):
        # Read ADC values
        voltage_reading = self.voltage_channel.voltage
        current_reading = self.current_channel.voltage

        # Convert ADC voltage to battery voltage (assuming 5:1 divider)
        battery_voltage = voltage_reading * 5.0  # Adjust ratio if different
        # Convert ADC voltage to Amps (ACS712 5A model = 185mV per A, 2.5V zero-current offset)
        current_amperes = (current_reading - 2.5) / 0.185

        # Clamp for safety
        battery_voltage = max(0.0, battery_voltage)

        # Publish voltage
        voltage_msg = Float32()
        voltage_msg.data = round(battery_voltage, 2)
        self.voltage_pub.publish(voltage_msg)

        # Publish current
        current_msg = Float32()
        current_msg.data = round(current_amperes, 2)
        self.current_pub.publish(current_msg)

        # Log readings
        self.get_logger().info(f"🔋 Voltage: {voltage_msg.data} V | ⚡ Current: {current_msg.data} A")

def main(args=None):
    rclpy.init(args=args)
    node = SensorMonitorNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
