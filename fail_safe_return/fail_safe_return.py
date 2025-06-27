import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from std_msgs.msg import Header
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import Bool
from builtin_interfaces.msg import Time

import math
import time

class ReturnToBaseNode(Node):
    def __init__(self):
        super().__init__('return_to_base_node')

        # Parameters
        self.heartbeat_timeout_sec = 10.0
        self.return_lat = 17.6868    # Example: Replace with base latitude
        self.return_lon = 83.2185    # Example: Replace with base longitude

        # State variables
        self.last_heartbeat_time = self.get_clock().now()
        self.connected = True
        self.current_lat = None
        self.current_lon = None

        # Subscribers
        self.create_subscription(Bool, 'heartbeat', self.heartbeat_callback, 10)
        self.create_subscription(NavSatFix, 'gnss/fix', self.gnss_callback, 10)

        # Publisher
        self.cmd_pub = self.create_publisher(Twist, 'cmd_vel', 10)

        # Timer to check connection state
        self.create_timer(1.0, self.check_heartbeat)

        self.get_logger().info('🛰️ ReturnToBaseNode Initialized')

    def heartbeat_callback(self, msg):
        if msg.data:
            self.last_heartbeat_time = self.get_clock().now()
            if not self.connected:
                self.get_logger().info('✅ Connection re-established.')
            self.connected = True

    def gnss_callback(self, msg):
        self.current_lat = msg.latitude
        self.current_lon = msg.longitude

    def check_heartbeat(self):
        time_diff = (self.get_clock().now() - self.last_heartbeat_time).nanoseconds / 1e9
        if time_diff > self.heartbeat_timeout_sec:
            if self.connected:
                self.get_logger().warn('❌ Heartbeat lost. Initiating Return to Base!')
                self.connected = False
            self.navigate_to_base()
        else:
            if self.connected:
                self.get_logger().debug('🔄 Connection OK.')

    def navigate_to_base(self):
        if self.current_lat is None or self.current_lon is None:
            self.get_logger().warn('❗ GNSS position not available. Cannot navigate.')
            return

        twist = Twist()

        # Simple logic: if we're far, publish forward velocity
        distance = self.haversine(self.current_lat, self.current_lon, self.return_lat, self.return_lon)
        self.get_logger().info(f'📍 Distance to base: {distance:.2f} m')

        if distance > 5.0:  # 5 meters threshold
            twist.linear.x = 0.5  # Simulated forward movement
            twist.angular.z = 0.0
            self.cmd_pub.publish(twist)
            self.get_logger().info('🚤 Returning to base...')
        else:
            twist.linear.x = 0.0
            self.cmd_pub.publish(twist)
            self.get_logger().info('🏠 Reached base station. Stopping.')

    def haversine(self, lat1, lon1, lat2, lon2):
        # Earth radius in meters
        R = 6371000
        phi1 = math.radians(lat1)
        phi2 = math.radians(lat2)
        delta_phi = math.radians(lat2 - lat1)
        delta_lambda = math.radians(lon2 - lon1)

        a = math.sin(delta_phi / 2.0) ** 2 + \
            math.cos(phi1) * math.cos(phi2) * \
            math.sin(delta_lambda / 2.0) ** 2

        c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))
        return R * c

def main(args=None):
    rclpy.init(args=args)
    node = ReturnToBaseNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
