import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from Phidget22.Devices.Spatial import Spatial
from Phidget22.Phidget import *
import time

class IMUNode(Node):
    def __init__(self):
        super().__init__('imu_node')

        # ROS 2 Publisher for /imu/data_raw
        self.publisher_ = self.create_publisher(Imu, 'imu/data_raw', 10)
        self.get_logger().info('📡 IMU Publisher Initialized')

        # Initialize and configure Phidgets IMU
        self.spatial = Spatial()
        self.spatial.setDeviceSerialNumber(0)  # Auto-detect
        self.spatial.setOnSpatialDataHandler(self.spatial_data_handler)

        try:
            self.spatial.openWaitForAttachment(5000)
            self.get_logger().info('✅ IMU Connected Successfully')
        except PhidgetException as e:
            self.get_logger().error(f'❌ IMU Connection Failed: {e.details}')
            rclpy.shutdown()

    def spatial_data_handler(self, _, spatial_data):
        imu_msg = Imu()

        # Timestamp and frame
        imu_msg.header.stamp = self.get_clock().now().to_msg()
        imu_msg.header.frame_id = 'imu_link'

        # Fill linear acceleration
        imu_msg.linear_acceleration.x = spatial_data.acceleration[0]
        imu_msg.linear_acceleration.y = spatial_data.acceleration[1]
        imu_msg.linear_acceleration.z = spatial_data.acceleration[2]

        # Fill angular velocity
        imu_msg.angular_velocity.x = spatial_data.angularRate[0]
        imu_msg.angular_velocity.y = spatial_data.angularRate[1]
        imu_msg.angular_velocity.z = spatial_data.angularRate[2]

        # Orientation not computed by raw IMU
        imu_msg.orientation.x = 0.0
        imu_msg.orientation.y = 0.0
        imu_msg.orientation.z = 0.0
        imu_msg.orientation.w = 1.0

        # Recommended: Add covariance for downstream use (e.g., EKF)
        imu_msg.orientation_covariance[0] = -1.0  # Marks orientation as unavailable
        imu_msg.angular_velocity_covariance[0] = 0.02
        imu_msg.linear_acceleration_covariance[0] = 0.04

        # Publish the IMU message
        self.publisher_.publish(imu_msg)

    def destroy_node(self):
        try:
            self.spatial.close()
        except:
            pass
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    imu_node = IMUNode()

    try:
        rclpy.spin(imu_node)
    except KeyboardInterrupt:
        pass
    finally:
        imu_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
