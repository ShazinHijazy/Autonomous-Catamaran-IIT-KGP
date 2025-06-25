from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',  # 🛠 Must match the package name in setup.py
            executable='imu_node',        # ✅ Must match the script (imu_node.py)
            name='imu_node',
            output='screen',
            remappings=[('/imu/data_raw', '/catamaran/imu/data_raw')]
        )
    ])
