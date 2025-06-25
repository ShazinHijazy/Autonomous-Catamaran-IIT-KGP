import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
import RPi.GPIO as GPIO
import time

# GPIO pin numbers (BCM mode)
TRIG_PIN = 23
ECHO_PIN = 24

class StaticUltrasonicNode(Node):
    def __init__(self):
        super().__init__('static_ultrasonic_node')
        self.get_logger().info("📡 Static Ultrasonic Node Initialized")

        # Create a publisher for Range messages
        self.publisher_ = self.create_publisher(Range, 'ultrasonic_static/range', 10)

        # Setup GPIO
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(TRIG_PIN, GPIO.OUT)
        GPIO.setup(ECHO_PIN, GPIO.IN)

        # Setup a periodic timer
        self.timer = self.create_timer(1.0, self.read_distance)

    def read_distance(self):
        try:
            # Ensure the trigger pin is low
            GPIO.output(TRIG_PIN, False)
            time.sleep(0.05)

            # Send trigger pulse
            GPIO.output(TRIG_PIN, True)
            time.sleep(0.00001)  # 10 microseconds
            GPIO.output(TRIG_PIN, False)

            # Wait for echo to start
            timeout = time.time() + 0.05
            while GPIO.input(ECHO_PIN) == 0 and time.time() < timeout:
                pulse_start = time.time()
            else:
                if time.time() >= timeout:
                    self.get_logger().warn("⚠️ Echo start timeout")
                    return

            # Wait for echo to end
            timeout = time.time() + 0.05
            while GPIO.input(ECHO_PIN) == 1 and time.time() < timeout:
                pulse_end = time.time()
            else:
                if time.time() >= timeout:
                    self.get_logger().warn("⚠️ Echo end timeout")
                    return

            # Calculate distance
            pulse_duration = pulse_end - pulse_start
            distance_cm = pulse_duration * 17150
            distance_cm = round(distance_cm, 2)

            # Filter out-of-range values
            if not (2.0 <= distance_cm <= 400.0):
                self.get_logger().warn(f"⚠️ Out-of-range reading: {distance_cm} cm")
                return

            # Create Range message
            range_msg = Range()
            range_msg.header.stamp = self.get_clock().now().to_msg()
            range_msg.header.frame_id = 'ultrasonic_static_sensor'
            range_msg.radiation_type = Range.ULTRASOUND
            range_msg.field_of_view = 0.26  # approx 15 degrees
            range_msg.min_range = 0.02
            range_msg.max_range = 4.0
            range_msg.range = distance_cm / 100.0  # meters

            # Publish message
            self.publisher_.publish(range_msg)
            self.get_logger().info(f"📏 Distance: {distance_cm} cm")

        except Exception as e:
            self.get_logger().error(f"❌ Sensor read error: {e}")

    def destroy_node(self):
        GPIO.cleanup()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = StaticUltrasonicNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
