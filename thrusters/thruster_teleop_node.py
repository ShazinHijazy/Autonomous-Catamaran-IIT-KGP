import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys
import termios
import tty
import select
import time
import os

# Constants for PWM
PWM_NEUTRAL = 1500
PWM_MIN = 1100
PWM_MAX = 1900
PWM_STEP = 40

class TeleopThrusterNode(Node):
    def __init__(self):
        super().__init__('teleop_thruster_node')
        self.publisher_ = self.create_publisher(Twist, '/teleop_cmd', 10)

        self.left_pwm = PWM_NEUTRAL
        self.right_pwm = PWM_NEUTRAL

        if sys.stdin.isatty():
            self.settings = termios.tcgetattr(sys.stdin)
        else:
            self.get_logger().error("❌ Not running in a terminal. Exiting.")
            rclpy.shutdown()
            exit(1)

        self.get_logger().info("🕹️ Teleop node ready. Use W/A/S/D to control the catamaran.")

    def get_key(self):
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        key = sys.stdin.read(1) if rlist else None
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, self.settings)
        return key

    def clear_console(self):
        os.system('cls' if os.name == 'nt' else 'clear')

    def display_status(self):
        self.clear_console()
        print("=== CATAMARAN TELEOP CONTROL ===")
        print("W/S: Forward / Backward")
        print("A/D: Turn Left / Right")
        print("R  : Reset to Neutral")
        print("Q  : Quit")
        print(f"\nLeft Thruster PWM : {self.left_pwm}")
        print(f"Right Thruster PWM: {self.right_pwm}")
        print("================================")

    def publish_pwm(self):
        msg = Twist()
        msg.linear.x = float(self.left_pwm)   # Left Thruster
        msg.angular.z = float(self.right_pwm) # Right Thruster
        self.publisher_.publish(msg)

    def run(self):
        self.display_status()
        self.publish_pwm()

        try:
            while rclpy.ok():
                key = self.get_key()
                updated = False

                if key == 'w':
                    self.left_pwm = min(PWM_MAX, self.left_pwm + PWM_STEP)
                    self.right_pwm = min(PWM_MAX, self.right_pwm + PWM_STEP)
                    updated = True

                elif key == 's':
                    self.left_pwm = max(PWM_MIN, self.left_pwm - PWM_STEP)
                    self.right_pwm = max(PWM_MIN, self.right_pwm - PWM_STEP)
                    updated = True

                elif key == 'a':
                    self.left_pwm = max(PWM_MIN, self.left_pwm - PWM_STEP)
                    self.right_pwm = min(PWM_MAX, self.right_pwm + PWM_STEP)
                    updated = True

                elif key == 'd':
                    self.left_pwm = min(PWM_MAX, self.left_pwm + PWM_STEP)
                    self.right_pwm = max(PWM_MIN, self.right_pwm - PWM_STEP)
                    updated = True

                elif key in ['r', 'R']:
                    self.left_pwm = PWM_NEUTRAL
                    self.right_pwm = PWM_NEUTRAL
                    updated = True

                elif key in ['q', 'Q']:
                    break

                if updated:
                    self.display_status()
                    self.publish_pwm()
                    time.sleep(0.05)

        except KeyboardInterrupt:
            pass

        finally:
            # Reset to neutral on exit
            self.left_pwm = PWM_NEUTRAL
            self.right_pwm = PWM_NEUTRAL
            self.publish_pwm()
            self.get_logger().info("🛑 Teleop node shut down.")

def main(args=None):
    rclpy.init(args=args)
    node = TeleopThrusterNode()
    node.run()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
