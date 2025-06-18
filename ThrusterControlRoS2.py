# teleop_thruster.py
import rclpy
from rclpy.node import Node
from custom_msgs.msg import ThrusterCommand
from pynput import keyboard

PWM_NEUTRAL = 1500
PWM_MAX = 1900
PWM_MIN = 1100
PWM_STEP = 20

class TeleopThruster(Node):
    def __init__(self):
        super().__init__('teleop_thruster')
        self.publisher = self.create_publisher(ThrusterCommand, 'thruster_cmd', 10)
        self.left_pwm = PWM_NEUTRAL
        self.right_pwm = PWM_NEUTRAL
        self.paused = False
        self.emergency_stop = False

    def send_command(self):
        msg = ThrusterCommand()
        msg.left_pwm = self.left_pwm
        msg.right_pwm = self.right_pwm
        msg.pause = self.paused
        msg.emergency_stop = self.emergency_stop
        self.publisher.publish(msg)

    def on_press(self, key):
        updated = False
        try:
            if key.char == 'w':
                self.left_pwm = min(PWM_MAX, self.left_pwm + PWM_STEP)
                self.right_pwm = min(PWM_MAX, self.right_pwm + PWM_STEP)
                updated = True
            elif key.char == 's':
                self.left_pwm = max(PWM_MIN, self.left_pwm - PWM_STEP)
                self.right_pwm = max(PWM_MIN, self.right_pwm - PWM_STEP)
                updated = True
            elif key.char == 'a':
                self.left_pwm = max(PWM_MIN, self.left_pwm - PWM_STEP)
                self.right_pwm = min(PWM_MAX, self.right_pwm + PWM_STEP)
                updated = True
            elif key.char == 'd':
                self.left_pwm = min(PWM_MAX, self.left_pwm + PWM_STEP)
                self.right_pwm = max(PWM_MIN, self.right_pwm - PWM_STEP)
                updated = True
            elif key.char == 'x':
                self.emergency_stop = not self.emergency_stop
                updated = True
            elif key.char == ' ':
                self.paused = not self.paused
                updated = True
            elif key.char == 'q':
                print('Quitting...')
                return False  # Stop listener
        except AttributeError:
            if key == keyboard.Key.up:
                self.right_pwm = min(PWM_MAX, self.right_pwm + PWM_STEP)
                updated = True
            elif key == keyboard.Key.down:
                self.right_pwm = max(PWM_MIN, self.right_pwm - PWM_STEP)
                updated = True
            elif key == keyboard.Key.left:
                self.left_pwm = max(PWM_MIN, self.left_pwm - PWM_STEP)
                updated = True
            elif key == keyboard.Key.right:
                self.left_pwm = min(PWM_MAX, self.left_pwm + PWM_STEP)
                updated = True

        if updated:
            self.send_command()

def main():
    rclpy.init()
    node = TeleopThruster()
    listener = keyboard.Listener(on_press=node.on_press)
    listener.start()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()