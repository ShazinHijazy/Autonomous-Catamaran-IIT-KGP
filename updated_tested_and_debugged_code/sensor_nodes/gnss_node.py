import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix, NavSatStatus

from DFRobot_GNSS import DFRobot_GNSS_I2C

class GNSSI2CNode(Node):
    def __init__(self):
        super().__init__('gnss_i2c_node')
        self.gnss = DFRobot_GNSS_I2C(1, 0x10)  # Bus 1, address 0x10
        self.gnss.begin()
        self.fix_pub = self.create_publisher(NavSatFix, 'fix', 10)
        self.timer = self.create_timer(1.0, self.timer_callback)  # 1Hz

    def timer_callback(self):
        lat = self.gnss.getLatitude()
        lon = self.gnss.getLongitude()
        alt = self.gnss.getAltitude()

        if lat is None or lon is None or (lat == 0.0 and lon == 0.0):
            self.get_logger().warn('No GNSS fix yet')
            return

        msg = NavSatFix()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'gnss_link'
        msg.status.status = NavSatStatus.STATUS_FIX
        msg.status.service = NavSatStatus.SERVICE_GPS
        msg.latitude = lat
        msg.longitude = lon
        msg.altitude = alt
        msg.position_covariance_type = NavSatFix.COVARIANCE_TYPE_UNKNOWN

        self.fix_pub.publish(msg)
        self.get_logger().info(f'GNSS: lat={lat:.7f}, lon={lon:.7f}, alt={alt:.2f}')

def main(args=None):
    rclpy.init(args=args)
    node = GNSSI2CNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
