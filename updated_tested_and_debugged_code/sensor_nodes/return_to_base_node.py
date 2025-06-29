import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from std_msgs.msg import String

class ReturnToBaseNode(Node):
    def __init__(self):
        super().__init__('return_to_base_node')
        self.goal_pub = self.create_publisher(PoseStamped, '/goal_pose', 10)

        # Base location (customize as needed)
        self.base_x = 0.0  # Set your base X in map frame
        self.base_y = 0.0  # Set your base Y in map frame
        self.base_yaw = 0.0  # Orientation angle in radians

        # Trigger subscriber (optional)
        self.create_subscription(String, '/return_home', self.trigger_callback, 10)
        self.get_logger().info("ReturnToBaseNode initialized. Waiting for /return_home trigger...")

    def trigger_callback(self, msg):
        if msg.data.lower() == 'return':
            self.get_logger().info('Return to base triggered!')
            self.send_return_goal()

    def send_return_goal(self):
        goal_msg = PoseStamped()
        goal_msg.header.frame_id = 'map'
        goal_msg.header.stamp = self.get_clock().now().to_msg()

        # Set position
        goal_msg.pose.position.x = self.base_x
        goal_msg.pose.position.y = self.base_y
        goal_msg.pose.position.z = 0.0

        # Set orientation as quaternion (here: facing forward)
        goal_msg.pose.orientation.w = 1.0  # No rotation (facing forward)

        self.goal_pub.publish(goal_msg)
        self.get_logger().info(f"Published return goal to base: x={self.base_x}, y={self.base_y}")

def main(args=None):
    rclpy.init(args=args)
    node = ReturnToBaseNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Shutting down ReturnToBaseNode.")
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
