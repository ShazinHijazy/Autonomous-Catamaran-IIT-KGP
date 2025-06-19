import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import sys, termios, tty, select, time, os, csv
from datetime import datetime

class CustomTeleop(Node):
    def __init__(self):
        super().__init__('custom_teleop')
        self.publisher = self.create_publisher(Twist, '/thruster_cmd', 10)
        self.get_logger().info("Custom teleop started.")

        # Speed control
        self.speed = 1.0
        self.speed_step = 0.2
        self.max_speed = 1.0
        self.min_speed = 0.2

        # Logging
        self.log_path = "/home/jaswanth/cat_ws/log_data/teleop_log.csv"
        os.makedirs(os.path.dirname(self.log_path), exist_ok=True)
        self.log_file = open(self.log_path, mode='w', newline='')
        self.logger = csv.writer(self.log_file)
        self.logger.writerow(['Timestamp', 'Key', 'Direction', 'Speed', 'Linear_X', 'Angular_Z'])

    def get_key(self):
        settings = termios.tcgetattr(sys.stdin)
        tty.setraw(sys.stdin.fileno())
        rlist, _, _ = select.select([sys.stdin], [], [], 0.05)
        key = sys.stdin.read(1) if rlist else ''
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
        return key

    def clear_terminal(self):
        os.system('clear' if os.name == 'posix' else 'cls')

    def display_hud(self, key, direction, linear, angular):
        self.clear_terminal()
        print("🛥️  Remote Catamaran Teleop - Live HUD")
        print("=======================================")
        print(f"🔁 Pressed Key       : {key.upper() if key else 'None'}")
        print(f"📍 Direction         : {direction}")
        print(f"⚡ Speed Multiplier  : {self.speed:.1f}")
        print(f"🚀 Linear Velocity   : {linear:.2f}")
        print(f"🌀 Angular Velocity  : {angular:.2f}")
        print("🕹️  Use W/A/S/D, Q/E/Z/C for arcs | +/- to adjust speed | SPACE to stop")
        print("=======================================")

    def log_data(self, key, direction, linear, angular):
        timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        self.logger.writerow([timestamp, key, direction, f"{self.speed:.1f}", f"{linear:.2f}", f"{angular:.2f}"])
        self.log_file.flush()

    def run(self):
        key_map = {
            'w': (1.0, 0.0, 'Forward'),
            's': (-1.0, 0.0, 'Reverse'),
            'd': (0.0, 1.0, 'Spin Right (CW)'),
            'a': (0.0, -1.0, 'Spin Left (CCW)'),
            'e': (1.0, 1.0, 'Forward + Right Arc'),
            'q': (1.0, -1.0, 'Forward + Left Arc'),
            'c': (-1.0, 1.0, 'Reverse + Right Arc'),
            'z': (-1.0, -1.0, 'Reverse + Left Arc'),
            ' ': (0.0, 0.0, 'Stop')
        }

        try:
            while rclpy.ok():
                key = self.get_key()
                linear = angular = 0.0
                direction = 'Idle'

                if key == '\x03':  # Ctrl+C
                    break
                elif key == '+':
                    self.speed = min(self.max_speed, self.speed + self.speed_step)
                    continue
                elif key == '-':
                    self.speed = max(self.min_speed, self.speed - self.speed_step)
                    continue
                elif key in key_map:
                    linear, angular, direction = key_map[key]
                    linear *= self.speed
                    angular *= self.speed

                    self.publish_twist(linear, angular)
                    self.display_hud(key, direction, linear, angular)
                    self.log_data(key, direction, linear, angular)
                    time.sleep(0.1)

        except KeyboardInterrupt:
            self.get_logger().info("Teleop interrupted.")
        finally:
            self.publish_twist(0.0, 0.0)
            self.log_file.close()

    def publish_twist(self, linear, angular):
        msg = Twist()
        msg.linear.x = linear
        msg.angular.z = angular
        self.publisher.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = CustomTeleop()
    node.run()
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
