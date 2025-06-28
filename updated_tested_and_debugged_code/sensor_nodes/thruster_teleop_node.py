import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import threading
import time

try:
    import keyboard
    KEYBOARD_AVAILABLE = True
except ImportError:
    KEYBOARD_AVAILABLE = False

MAX_SPEED = 1.0
MIN_SPEED = -1.0
STEP = 0.1

INSTRUCTIONS = """
Catamaran Thruster Teleop Node

Controls:
  w: Forward
  s: Backward
  a: Turn left
  d: Turn right
  X: Emergency stop (reset both thrusters to 0)
  Space: Pause/Resume teleop commands
  Q: Quit teleop node
  Left Arrow: Increase left thruster speed
  Right Arrow: Decrease left thruster speed
  Up Arrow: Increase right thruster speed
  Down Arrow: Decrease right thruster speed

Focus the terminal window and use keys as above.
"""

class ThrusterTeleopNode(Node):
    def __init__(self):
        super().__init__('thruster_teleop_node')
        self.pub = self.create_publisher(Twist, '/cmd_vel_teleop', 10)
        self.running = True
        self.paused = False
        self.left_speed = 0.0
        self.right_speed = 0.0
        self.last_cmd = Twist()
        self.key_last_time = {}

        if not KEYBOARD_AVAILABLE:
            self.get_logger().error("The 'keyboard' Python module is required. Install with: pip install keyboard")
            print(INSTRUCTIONS)
            exit(1)

        print(INSTRUCTIONS)
        self.get_logger().info("Teleop node started. Use asdw, arrows, X, space, Q.")

        self.listener_thread = threading.Thread(target=self.keyboard_listener)
        self.listener_thread.daemon = True
        self.listener_thread.start()
        self.timer = self.create_timer(0.1, self.publish_cmd)

    def debounce(self, key, interval=0.15):
        now = time.time()
        last = self.key_last_time.get(key, 0)
        if now - last > interval:
            self.key_last_time[key] = now
            return True
        return False

    def keyboard_listener(self):
        while self.running:
            try:
                if keyboard.is_pressed('q') and self.debounce('q', 0.5):
                    self.get_logger().info("Quitting teleop node.")
                    self.running = False
                    break
                if keyboard.is_pressed(' ') and self.debounce('space', 0.5):
                    self.paused = not self.paused
                    status = "Paused" if self.paused else "Resumed"
                    self.get_logger().info(f"{status} teleop commands.")
                if keyboard.is_pressed('x') and self.debounce('x', 0.5):
                    self.left_speed = 0.0
                    self.right_speed = 0.0
                    self.get_logger().warn("EMERGENCY STOP!")
                if keyboard.is_pressed('w') and self.debounce('w'):
                    self.left_speed = min(self.left_speed + STEP, MAX_SPEED)
                    self.right_speed = min(self.right_speed + STEP, MAX_SPEED)
                if keyboard.is_pressed('s') and self.debounce('s'):
                    self.left_speed = max(self.left_speed - STEP, MIN_SPEED)
                    self.right_speed = max(self.right_speed - STEP, MIN_SPEED)
                if keyboard.is_pressed('a') and self.debounce('a'):
                    self.left_speed = max(self.left_speed - STEP, MIN_SPEED)
                    self.right_speed = min(self.right_speed + STEP, MAX_SPEED)
                if keyboard.is_pressed('d') and self.debounce('d'):
                    self.left_speed = min(self.left_speed + STEP, MAX_SPEED)
                    self.right_speed = max(self.right_speed - STEP, MIN_SPEED)
                # Arrow key logic:
                if keyboard.is_pressed('left') and self.debounce('left'):
                    self.left_speed = min(self.left_speed + STEP, MAX_SPEED)
                if keyboard.is_pressed('right') and self.debounce('right'):
                    self.left_speed = max(self.left_speed - STEP, MIN_SPEED)
                if keyboard.is_pressed('up') and self.debounce('up'):
                    self.right_speed = min(self.right_speed + STEP, MAX_SPEED)
                if keyboard.is_pressed('down') and self.debounce('down'):
                    self.right_speed = max(self.right_speed - STEP, MIN_SPEED)
                time.sleep(0.01)
            except Exception as e:
                self.get_logger().error(f"Keyboard input error: {e}")
                break

    def publish_cmd(self):
        if not self.running:
            rclpy.shutdown()
            return
        if self.paused:
            return
        self.left_speed = max(MIN_SPEED, min(MAX_SPEED, self.left_speed))
        self.right_speed = max(MIN_SPEED, min(MAX_SPEED, self.right_speed))
        msg = Twist()
        msg.linear.x = (self.left_speed + self.right_speed) / 2.0
        msg.angular.z = (self.right_speed - self.left_speed) / 2.0
        if msg.linear.x != self.last_cmd.linear.x or msg.angular.z != self.last_cmd.angular.z:
            self.pub.publish(msg)
            self.last_cmd = msg

def main(args=None):
    rclpy.init(args=args)
    node = ThrusterTeleopNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.running = False
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
