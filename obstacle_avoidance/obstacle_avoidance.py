import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan, Range

class ObstacleAvoidanceNode(Node):
    def __init__(self):
        super().__init__('obstacle_avoidance_node')

        # Thresholds for obstacle detection
        self.lidar_threshold = 1.0  # in meters
        self.ultrasonic_threshold = 0.4  # close range threshold

        # Initialize sensor readings
        self.lidar_obstacle = False
        self.ultrasonic_front = float('inf')
        self.ultrasonic_side = float('inf')

        # Publisher for movement commands
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        # Subscribers for sensor data
        self.create_subscription(LaserScan, '/scan', self.lidar_callback, 10)
        self.create_subscription(Range, '/ultrasonic/front', self.front_ultrasonic_callback, 10)
        self.create_subscription(Range, '/ultrasonic/side', self.side_ultrasonic_callback, 10)

        # Main control loop (5Hz)
        self.timer = self.create_timer(0.2, self.control_loop)

        self.get_logger().info("✅ Obstacle Avoidance Node Initialized")

    def lidar_callback(self, msg: LaserScan):
        """Processes the LaserScan data to check for obstacles ahead."""
        front_range_indices = range(len(msg.ranges)//2 - 15, len(msg.ranges)//2 + 15)
        self.lidar_obstacle = any(
            0.05 < msg.ranges[i] < self.lidar_threshold for i in front_range_indices
            if not (msg.ranges[i] == float('inf') or msg.ranges[i] == 0.0)
        )

    def front_ultrasonic_callback(self, msg: Range):
        """Updates the front ultrasonic reading."""
        self.ultrasonic_front = msg.range

    def side_ultrasonic_callback(self, msg: Range):
        """Updates the side ultrasonic reading (left or right)."""
        self.ultrasonic_side = msg.range

    def control_loop(self):
        """Decides whether to move forward, stop, or turn."""
        twist = Twist()

        if self.ultrasonic_front < self.ultrasonic_threshold:
            self.get_logger().info("⚠️ Close obstacle detected (Ultrasonic Front)")
            twist.linear.x = 0.0
            twist.angular.z = 0.5 if self.ultrasonic_side > self.ultrasonic_threshold else -0.5

        elif self.lidar_obstacle:
            self.get_logger().info("⚠️ Obstacle detected (Lidar)")
            twist.linear.x = 0.0
            twist.angular.z = 0.4

        else:
            twist.linear.x = 0.5
            twist.angular.z = 0.0

        self.cmd_vel_pub.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = ObstacleAvoidanceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
