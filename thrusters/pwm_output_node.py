import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import pigpio

class PWMOutputNode(Node):
    def __init__(self):
        super().__init__('pwm_output_node')

        # Declare GPIO pin parameters with defaults
        self.declare_parameter('left_thruster_pin', 18)
        self.declare_parameter('right_thruster_pin', 19)

        self.left_pin = self.get_parameter('left_thruster_pin').get_parameter_value().integer_value
        self.right_pin = self.get_parameter('right_thruster_pin').get_parameter_value().integer_value

        self.get_logger().info(f"Using GPIO Pins - Left: {self.left_pin}, Right: {self.right_pin}")

        # Initialize pigpio
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("❌ pigpio daemon not running. Please start it using 'sudo pigpiod'")
            rclpy.shutdown()
            return

        # Set pins as servo outputs
        self.pi.set_mode(self.left_pin, pigpio.OUTPUT)
        self.pi.set_mode(self.right_pin, pigpio.OUTPUT)

        # Set neutral PWM
        self.pi.set_servo_pulsewidth(self.left_pin, 1500)
        self.pi.set_servo_pulsewidth(self.right_pin, 1500)

        self.get_logger().info("✅ PWM Output Node Initialized")

        # Subscriber to /thruster_cmd topic
        self.subscription = self.create_subscription(
            Twist,
            '/thruster_cmd',
            self.cmd_callback,
            10
        )

    def cmd_callback(self, msg: Twist):
        left_pwm = int(msg.linear.x)
        right_pwm = int(msg.angular.z)

        # Clamp PWM to valid range
        left_pwm = max(1100, min(1900, left_pwm))
        right_pwm = max(1100, min(1900, right_pwm))

        self.pi.set_servo_pulsewidth(self.left_pin, left_pwm)
        self.pi.set_servo_pulsewidth(self.right_pin, right_pwm)

        self.get_logger().info(f"🔧 PWM Sent - Left: {left_pwm} us, Right: {right_pwm} us")

    def destroy_node(self):
        # Reset pins on shutdown
        self.pi.set_servo_pulsewidth(self.left_pin, 0)
        self.pi.set_servo_pulsewidth(self.right_pin, 0)
        self.pi.stop()
        self.get_logger().info("🛑 PWM Outputs Disabled")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = PWMOutputNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('🔌 Shutting down PWM Output Node...')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
