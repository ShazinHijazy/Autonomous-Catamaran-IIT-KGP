import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import pigpio
import sys

# Constants
PWM_NEUTRAL = 1500
PWM_MIN = 1100
PWM_MAX = 1900

GPIO_LEFT_THRUSTER = 18   # BCM GPIO pin for left ESC
GPIO_RIGHT_THRUSTER = 19  # BCM GPIO pin for right ESC

class ThrusterControlNode(Node):
    def __init__(self):
        super().__init__('thruster_control_node')
        self.get_logger().info('🚀 Thruster Control Node Initialized')

        # Connect to pigpio daemon
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error('❌ pigpio daemon not running. Start it using: sudo pigpiod')
            rclpy.shutdown()
            sys.exit(1)

        # Set GPIO pins as output for ESCs
        self.pi.set_mode(GPIO_LEFT_THRUSTER, pigpio.OUTPUT)
        self.pi.set_mode(GPIO_RIGHT_THRUSTER, pigpio.OUTPUT)

        # Initialize ESCs to neutral
        self.set_thruster_pwm(PWM_NEUTRAL, PWM_NEUTRAL)

        # Subscribe to Twist messages
        self.subscription = self.create_subscription(
            Twist,
            '/thruster_cmd',
            self.thruster_callback,
            10
        )

    def clamp_pwm(self, value):
        return max(PWM_MIN, min(PWM_MAX, int(value)))

    def set_thruster_pwm(self, left_pwm, right_pwm):
        self.pi.set_servo_pulsewidth(GPIO_LEFT_THRUSTER, self.clamp_pwm(left_pwm))
        self.pi.set_servo_pulsewidth(GPIO_RIGHT_THRUSTER, self.clamp_pwm(right_pwm))
        self.get_logger().info(f'✅ Thrusters Set | Left: {left_pwm} μs | Right: {right_pwm} μs')

    def thruster_callback(self, msg: Twist):
        left_pwm = msg.linear.x
        right_pwm = msg.angular.z
        self.set_thruster_pwm(left_pwm, right_pwm)

    def destroy_node(self):
        # Reset ESCs to neutral before shutdown
        self.set_thruster_pwm(PWM_NEUTRAL, PWM_NEUTRAL)
        self.pi.stop()
        self.get_logger().info('🛑 Thruster Control Node Shutdown')
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ThrusterControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
