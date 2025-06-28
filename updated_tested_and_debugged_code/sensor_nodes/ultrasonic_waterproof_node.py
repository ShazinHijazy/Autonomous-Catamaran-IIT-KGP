"""
ultrasonic_waterproof_node.py

ROS 2 node for the AJ-SR04M waterproof ultrasonic sensor.
Publishes distance readings as sensor_msgs/Range on the /ultrasonic_aj/range topic.

Hardware:
- Sensor: AJ-SR04M (waterproof ultrasonic)
- Platform: Raspberry Pi (BCM GPIO numbering)
- VCC: 5V (physical pin 2 or 4)
- GND: GND (physical pin 6 or 14)
- TRIG: GPIO 23 (physical pin 16)
- ECHO: GPIO 24 (physical pin 18)
"""

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Range
import RPi.GPIO as GPIO
import time

# === Pin Configuration ===
TRIG_PIN = 23  # GPIO23, physical pin 16
ECHO_PIN = 24  # GPIO24, physical pin 18

# === Sensor Range (meters) ===
MIN_RANGE = 0.20   # 20 cm
MAX_RANGE = 4.5    # 450 cm

class UltrasonicWaterproofNode(Node):
    def __init__(self):
        super().__init__('ultrasonic_waterproof_node')

        # GPIO setup
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(TRIG_PIN, GPIO.OUT)
        GPIO.setup(ECHO_PIN, GPIO.IN)
        GPIO.output(TRIG_PIN, False)
        time.sleep(2)  # Sensor settle time

        # ROS 2 publisher
        self.publisher = self.create_publisher(Range, 'ultrasonic_aj/range', 10)
        self.timer = self.create_timer(0.1, self.loop)  # 10 Hz

    def measure_distance(self):
        # Trigger the sensor
        GPIO.output(TRIG_PIN, True)
        time.sleep(0.00001)
        GPIO.output(TRIG_PIN, False)

        # Wait for echo start
        timeout = time.time() + 0.04
        pulse_start = time.time()
        while GPIO.input(ECHO_PIN) == 0:
            pulse_start = time.time()
            if pulse_start > timeout:
                self.get_logger().warn('Echo start timeout')
                return None

        # Wait for echo end
        pulse_end = time.time()
        while GPIO.input(ECHO_PIN) == 1:
            pulse_end = time.time()
            if pulse_end > timeout:
                self.get_logger().warn('Echo end timeout')
                return None

        pulse_duration = pulse_end - pulse_start
        distance = pulse_duration * 17150  # cm

        if distance < MIN_RANGE * 100 or distance > MAX_RANGE * 100:
            return None
        return distance / 100.0  # meters

    def loop(self):
        dist = self.measure_distance()
        msg = Range()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'ultrasonic_aj_link'
        msg.radiation_type = Range.ULTRASOUND
        msg.field_of_view = 0.75  # AJ-SR04M beam angle (approximate)
        msg.min_range = MIN_RANGE
        msg.max_range = MAX_RANGE

        if dist is not None:
            msg.range = dist
            self.publisher.publish(msg)
            self.get_logger().info(f'AJ-SR04M Distance: {dist:.2f} m')
        else:
            msg.range = float('inf')
            self.publisher.publish(msg)
            self.get_logger().warn('No valid distance reading (out of range or timeout)')

    def destroy_node(self):
        GPIO.cleanup()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = UltrasonicWaterproofNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
