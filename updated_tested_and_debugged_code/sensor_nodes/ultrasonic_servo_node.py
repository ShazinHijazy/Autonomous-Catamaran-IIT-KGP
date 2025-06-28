import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
import RPi.GPIO as GPIO
import time
from adafruit_servokit import ServoKit

TRIG_PIN = 17
ECHO_PIN = 27
SERVO_CHANNEL = 0
ANGLE_STEP = 5
SLEEP_BETWEEN_STEPS = 0.1  # seconds

class SweepUltrasonicNode(Node):
    def __init__(self):
        super().__init__('sweep_ultrasonic_node')

        # GPIO setup
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(TRIG_PIN, GPIO.OUT)
        GPIO.setup(ECHO_PIN, GPIO.IN)
        GPIO.output(TRIG_PIN, False)
        time.sleep(2)  # Allow sensor to settle

        # Servo setup
        self.kit = ServoKit(channels=16)
        self.angle = 0
        self.direction = 1  # 1 for increasing, -1 for decreasing

        self.publisher = self.create_publisher(Range, 'ultrasonic_scan', 10)
        self.timer = self.create_timer(SLEEP_BETWEEN_STEPS, self.loop)

    def measure_distance(self):
        # Trigger pulse
        GPIO.output(TRIG_PIN, True)
        time.sleep(0.00001)
        GPIO.output(TRIG_PIN, False)

        # Wait for echo start
        timeout = time.time() + 0.04  # 40 ms timeout
        pulse_start = time.time()
        while GPIO.input(ECHO_PIN) == 0:
            pulse_start = time.time()
            if pulse_start > timeout:
                return None

        # Wait for echo end
        pulse_end = time.time()
        while GPIO.input(ECHO_PIN) == 1:
            pulse_end = time.time()
            if pulse_end > timeout:
                return None

        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration * 17150  # cm

        if distance < 2 or distance > 400:
            return None  # Out of range
        return distance / 100.0  # meters

    def loop(self):
        # Move servo
        try:
            self.kit.servo[SERVO_CHANNEL].angle = self.angle
            time.sleep(0.05)  # Let servo reach position
        except Exception as e:
            self.get_logger().warn(f"Servo error at angle {self.angle}: {e}")
            return

        # Measure distance
        dist = self.measure_distance()
        if dist is not None:
            msg = Range()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = f'ultrasonic_angle_{self.angle}'
            msg.radiation_type = Range.ULTRASOUND
            msg.field_of_view = 0.26
            msg.min_range = 0.02
            msg.max_range = 4.0
            msg.range = dist
            self.publisher.publish(msg)
            self.get_logger().info(f'Angle: {self.angle}°, Distance: {dist:.2f} m')
        else:
            self.get_logger().warn(f"No valid distance at angle {self.angle}")

        # Update angle for next step
        self.angle += ANGLE_STEP * self.direction
        if self.angle >= 180:
            self.angle = 180
            self.direction = -1
        elif self.angle <= 0:
            self.angle = 0
            self.direction = 1

    def destroy_node(self):
        GPIO.cleanup()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = SweepUltrasonicNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
