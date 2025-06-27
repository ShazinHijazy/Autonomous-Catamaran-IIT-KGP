import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu, NavSatFix
from std_msgs.msg import Float32, String

import csv
import os
from datetime import datetime

class DataLogger(Node):
    def __init__(self):
        super().__init__('data_logger')

        # Set up logging directory
        log_dir = os.path.expanduser('~/catamaran_logs')
        os.makedirs(log_dir, exist_ok=True)

        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        log_path = os.path.join(log_dir, f'catamaran_log_{timestamp}.csv')

        # Open CSV file for logging
        self.csv_file = open(log_path, 'w', newline='')
        self.csv_writer = csv.writer(self.csv_file)
        self.csv_writer.writerow([
            'timestamp',
            'latitude', 'longitude',
            'imu_acc_x', 'imu_acc_y', 'imu_acc_z',
            'imu_gyro_x', 'imu_gyro_y', 'imu_gyro_z',
            'voltage', 'current',
            'obstacle_status'
        ])

        # Store latest sensor values
        self.latest_data = {
            'lat': 0.0,
            'lon': 0.0,
            'acc': [0.0, 0.0, 0.0],
            'gyro': [0.0, 0.0, 0.0],
            'volt': 0.0,
            'curr': 0.0,
            'obstacle': "No Data"
        }

        # Subscriptions
        self.create_subscription(NavSatFix, '/gps/fix', self.gps_callback, 10)
        self.create_subscription(Imu, '/imu/data_raw', self.imu_callback, 10)
        self.create_subscription(Float32, '/power/voltage', self.voltage_callback, 10)
        self.create_subscription(Float32, '/power/current', self.current_callback, 10)
        self.create_subscription(String, '/obstacle', self.obstacle_callback, 10)

        # Periodic logging every 1 sec
        self.timer = self.create_timer(1.0, self.log_data)
        self.get_logger().info(f'📁 Logging to: {log_path}')

    def gps_callback(self, msg):
        self.latest_data['lat'] = msg.latitude
        self.latest_data['lon'] = msg.longitude

    def imu_callback(self, msg):
        self.latest_data['acc'] = [
            msg.linear_acceleration.x,
            msg.linear_acceleration.y,
            msg.linear_acceleration.z
        ]
        self.latest_data['gyro'] = [
            msg.angular_velocity.x,
            msg.angular_velocity.y,
            msg.angular_velocity.z
        ]

    def voltage_callback(self, msg):
        self.latest_data['volt'] = msg.data

    def current_callback(self, msg):
        self.latest_data['curr'] = msg.data

    def obstacle_callback(self, msg):
        self.latest_data['obstacle'] = msg.data

    def log_data(self):
        now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        row = [
            now,
            self.latest_data['lat'],
            self.latest_data['lon'],
            *self.latest_data['acc'],
            *self.latest_data['gyro'],
            self.latest_data['volt'],
            self.latest_data['curr'],
            self.latest_data['obstacle']
        ]
        self.csv_writer.writerow(row)
        self.csv_file.flush()

    def destroy_node(self):
        self.csv_file.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = DataLogger()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
