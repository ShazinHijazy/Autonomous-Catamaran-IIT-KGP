import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys, termios, tty, select, time, os

class CustomTeleop(Node):
    def __init__(self):
        super().__init__('custom_teleop')
        self.publisher = self.create_publisher(Twist, '/thruster_cmd', 10)
        self.get_logger().info("Custom teleop started. Use W/A/S/D keys. + to speed up, - to slow down. SPACE to stop. CTRL+C to exit.")

        # Speed control settings
        self.speed = 1.0
        self.speed_step = 0.2
        self.max_speed = 1.0
        self.min_speed = 0.2

    def get_key(self):
        settings = termios.tcgetattr(sys.stdin)
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.05)
        key = sys.stdin.read(1) if rlist else ''
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        return key

    def clear_terminal(self):
        os.system('clear' if os.name == 'posix' else 'cls')

    def display_hud(self, keys, linear, angular):
        self.clear_terminal()
        print("🛥️  Remote Catamaran Teleop - Live HUD")
        print("=======================================")
        print(f"🔁 Pressed Keys     : {' + '.join(sorted(keys)) if keys else 'None'}")
        print(f"⚡ Speed Multiplier : {self.speed:.1f} (press '+' or '-' to change)")
        print(f"🚀 Linear Velocity  : {linear:.2f}")
        print(f"🌀 Angular Velocity : {angular:.2f}")
        print("🕹️  Use W/A/S/D | SPACE to stop | CTRL+C to exit")
        print("=======================================")

    def run(self):
        key_buffer = set()

        key_map = {
            'w': (1.0, 0.0),
            's': (-1.0, 0.0),
            'a': (0.0, 1.0),
            'd': (0.0, -1.0),
        }

        combo_map = {
            ('a', 'w'): (1.0, 1.0),
            ('d', 'w'): (1.0, -1.0),
            ('a', 's'): (-1.0, 1.0),
            ('d', 's'): (-1.0, -1.0),
        }

        try:
            while rclpy.ok():
                key = self.get_key()

                if key == '\x03':  # Ctrl+C
                    break

                elif key == '+':
                    self.speed = min(self.max_speed, self.speed + self.speed_step)
                    continue
                elif key == '-':
                    self.speed = max(self.min_speed, self.speed - self.speed_step)
                    continue
                elif key == ' ':
                    key_buffer.clear()
                    self.publish_twist(0.0, 0.0)
                    self.display_hud(key_buffer, 0.0, 0.0)
                    continue
                elif key in key_map:
                    if key in key_buffer:
                        key_buffer.remove(key)
                    else:
                        key_buffer.add(key)

                linear = 0.0
                angular = 0.0

                if len(key_buffer) == 1:
                    k = next(iter(key_buffer))
                    linear, angular = key_map.get(k, (0.0, 0.0))
                elif len(key_buffer) == 2:
                    combo_key = tuple(sorted(key_buffer))
                    linear, angular = combo_map.get(combo_key, (0.0, 0.0))

                # Apply speed multiplier
                linear *= self.speed
                angular *= self.speed

                self.publish_twist(linear, angular)
                self.display_hud(key_buffer, linear, angular)
                time.sleep(0.1)

        except KeyboardInterrupt:
            self.get_logger().info("Teleop interrupted by user.")
        finally:
            self.publish_twist(0.0, 0.0)

    def publish_twist(self, linear, angular):
        msg = Twist()
        msg.linear.x = linear
        msg.angular.z = angular
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    teleop_node = CustomTeleop()
    teleop_node.run()
    teleop_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
