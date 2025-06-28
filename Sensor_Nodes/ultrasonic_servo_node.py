import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
from std_msgs.msg import Float32
import RPi.GPIO as GPIO
import time

# GPIO pin numbers
TRIG = 17
ECHO = 27
SERVO = 12

# Constants
MIN_ANGLE = 0
MAX_ANGLE = 180
STEP = 15

class UltrasonicScannerNode(Node):
    def __init__(self):
        super().__init__('ultrasonic_scanner_node')

        # ROS Publishers
        self.range_pub = self.create_publisher(Range, 'ultrasonic/range', 10)
        self.angle_pub = self.create_publisher(Float32, 'ultrasonic/servo_angle', 10)
        self.get_logger().info('📡 Ultrasonic Scanner Node Initialized')

        # GPIO setup
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(TRIG, GPIO.OUT)
        GPIO.setup(ECHO, GPIO.IN)
        GPIO.setup(SERVO, GPIO.OUT)

        self.servo = GPIO.PWM(SERVO, 50)  # 50Hz
        self.servo.start(0)

        self.angle = MIN_ANGLE
        self.direction = 1  # 1: increasing, -1: decreasing

        # Start periodic scanning
        self.timer = self.create_timer(1.0, self.scan)

    def set_servo_angle(self, angle):
        duty = 2 + (angle / 18)
        self.servo.ChangeDutyCycle(duty)
        time.sleep(0.3)
        self.servo.ChangeDutyCycle(0)  # Stop signal to avoid jitter

    def measure_distance(self):
        # Trigger pulse
        GPIO.output(TRIG, False)
        time.sleep(0.05)
        GPIO.output(TRIG, True)
        time.sleep(0.00001)
        GPIO.output(TRIG, False)

        # Wait for echo with timeout
        timeout_start = time.time()
        while GPIO.input(ECHO) == 0 and (time.time() - timeout_start) < 0.05:
            pulse_start = time.time()

        timeout_start = time.time()
        while GPIO.input(ECHO) == 1 and (time.time() - timeout_start) < 0.05:
            pulse_end = time.time()

        # Duration calculation
        try:
            pulse_duration = pulse_end - pulse_start
        except:
            return -1  # Invalid reading

        distance = pulse_duration * 17150  # cm
        return round(distance, 2)

    def scan(self):
        self.set_servo_angle(self.angle)
        distance = self.measure_distance()

        if distance > 0 and distance < 400:  # Valid range
            msg = Range()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = 'ultrasonic_sensor'
            msg.radiation_type = Range.ULTRASOUND
            msg.field_of_view = 0.2  # Adjust based on actual specs
            msg.min_range = 2.0
            msg.max_range = 400.0
            msg.range = distance
            self.range_pub.publish(msg)

            angle_msg = Float32()
            angle_msg.data = float(self.angle)
            self.angle_pub.publish(angle_msg)

        # Sweep direction logic
        self.angle += STEP * self.direction
        if self.angle >= MAX_ANGLE or self.angle <= MIN_ANGLE:
            self.direction *= -1

    def destroy_node(self):
        self.get_logger().info("🔻 Cleaning up GPIO and shutting down...")
        self.servo.stop()
        GPIO.cleanup()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicScannerNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
