import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import String
import pigpio

# GPIO pin numbers (BCM numbering)
LEFT_GPIO = 17
RIGHT_GPIO = 18

PWM_NEUTRAL = 1500  # microseconds (ESC neutral)
PWM_RANGE = 400     # range for full forward/reverse
PWM_MIN = 1100
PWM_MAX = 1900

class ThrusterControlNode(Node):
    def __init__(self):
        super().__init__('thruster_control_node')
        self.mode = "autonomous"
        self.last_msg_time = self.get_clock().now()
        self.last_left_pwm = PWM_NEUTRAL
        self.last_right_pwm = PWM_NEUTRAL

        # ROS subscriptions
        self.create_subscription(Twist, '/cmd_vel', self.autonomous_cb, 10)
        self.create_subscription(Twist, '/cmd_vel_teleop', self.teleop_cb, 10)
        self.create_subscription(String, '/control_mode', self.mode_cb, 10)

        # pigpio setup
        self.pi = pigpio.pi()
        if not self.pi.connected:
            self.get_logger().error("Could not connect to pigpio daemon! Is it running?")
            exit(1)
        self.pi.set_mode(LEFT_GPIO, pigpio.OUTPUT)
        self.pi.set_mode(RIGHT_GPIO, pigpio.OUTPUT)
        self.set_thruster_pwm(LEFT_GPIO, PWM_NEUTRAL)
        self.set_thruster_pwm(RIGHT_GPIO, PWM_NEUTRAL)
        self.get_logger().info(f"Thruster node started. Left: GPIO {LEFT_GPIO}, Right: GPIO {RIGHT_GPIO} (AUTONOMOUS mode)")

        self.timer = self.create_timer(0.1, self.safety_check)

    def mode_cb(self, msg):
        mode = msg.data.lower()
        if mode in ["autonomous", "teleop"]:
            if self.mode != mode:
                self.mode = mode
                self.get_logger().info(f"Switched to {self.mode.upper()} mode.")
        else:
            self.get_logger().warn(f"Invalid mode '{msg.data}' received. Mode unchanged.")

    def autonomous_cb(self, msg):
        if self.mode == "autonomous":
            self.process_cmd(msg)

    def teleop_cb(self, msg):
        if self.mode == "teleop":
            self.process_cmd(msg)

    def process_cmd(self, msg):
        # Clamp input
        linear = max(-1.0, min(1.0, msg.linear.x))
        angular = max(-1.0, min(1.0, msg.angular.z))
        left = max(-1.0, min(1.0, linear - angular))
        right = max(-1.0, min(1.0, linear + angular))
        left_pwm = int(PWM_NEUTRAL + PWM_RANGE * left)
        right_pwm = int(PWM_NEUTRAL + PWM_RANGE * right)
        left_pwm = max(PWM_MIN, min(PWM_MAX, left_pwm))
        right_pwm = max(PWM_MIN, min(PWM_MAX, right_pwm))

        # Only log if changed
        if left_pwm != self.last_left_pwm or right_pwm != self.last_right_pwm:
            self.get_logger().info(f"Left PWM: {left_pwm}, Right PWM: {right_pwm}")

        self.set_thruster_pwm(LEFT_GPIO, left_pwm)
        self.set_thruster_pwm(RIGHT_GPIO, right_pwm)
        self.last_left_pwm = left_pwm
        self.last_right_pwm = right_pwm
        self.last_msg_time = self.get_clock().now()

    def set_thruster_pwm(self, gpio, pwm_us):
        self.pi.set_servo_pulsewidth(gpio, pwm_us)

    def safety_check(self):
        now = self.get_clock().now()
        # Stop thrusters if no command received for 1 second
        if (now - self.last_msg_time).nanoseconds > 1e9:
            if self.last_left_pwm != PWM_NEUTRAL or self.last_right_pwm != PWM_NEUTRAL:
                self.get_logger().warn("No command received in 1s, stopping thrusters.")
                self.set_thruster_pwm(LEFT_GPIO, PWM_NEUTRAL)
                self.set_thruster_pwm(RIGHT_GPIO, PWM_NEUTRAL)
                self.last_left_pwm = PWM_NEUTRAL
                self.last_right_pwm = PWM_NEUTRAL

    def destroy_node(self):
        self.set_thruster_pwm(LEFT_GPIO, 0)
        self.set_thruster_pwm(RIGHT_GPIO, 0)
        self.pi.stop()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ThrusterControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
