import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import pigpio

# GPIO pins for ESCs
ESC_LEFT_PIN = 17
ESC_RIGHT_PIN = 18

# PWM parameters (microseconds)
PWM_NEUTRAL = 1500
PWM_MIN = 1100
PWM_MAX = 1900

class ThrusterController(Node):
    def __init__(self):
        super().__init__('thruster_controller')
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("Could not connect to pigpio daemon.")
            raise RuntimeError("pigpio not running")
        self.pi.set_servo_pulsewidth(ESC_LEFT_PIN, PWM_NEUTRAL)
        self.pi.set_servo_pulsewidth(ESC_RIGHT_PIN, PWM_NEUTRAL)
        self.subscription = self.create_subscription(
            Twist,
            '/thruster_cmd',
            self.listener_callback,
            10)
        self.get_logger().info('ThrusterController node started.')

    def listener_callback(self, msg):
        # Differential thrust logic
        forward = msg.linear.x  # -1.0 (full reverse) to 1.0 (full forward)
        turn = msg.angular.z    # -1.0 (left) to 1.0 (right)

        left_cmd = forward - turn
        right_cmd = forward + turn

        left_pwm = int(PWM_NEUTRAL + left_cmd * (PWM_MAX - PWM_NEUTRAL))
        right_pwm = int(PWM_NEUTRAL + right_cmd * (PWM_MAX - PWM_NEUTRAL))

        left_pwm = max(PWM_MIN, min(PWM_MAX, left_pwm))
        right_pwm = max(PWM_MIN, min(PWM_MAX, right_pwm))

        self.pi.set_servo_pulsewidth(ESC_LEFT_PIN, left_pwm)
        self.pi.set_servo_pulsewidth(ESC_RIGHT_PIN, right_pwm)
        self.get_logger().info(f"Set left: {left_pwm}, right: {right_pwm}")

    def destroy_node(self):
        self.pi.set_servo_pulsewidth(ESC_LEFT_PIN, PWM_NEUTRAL)
        self.pi.set_servo_pulsewidth(ESC_RIGHT_PIN, PWM_NEUTRAL)
        self.pi.stop()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ThrusterController()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
