from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    rviz_config_path = os.path.join(
        get_package_share_directory('sensor_nodes'),
        'rviz',
        'catamaran.rviz'
    )

    return LaunchDescription([
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=['-d', rviz_config_path]
        )
    ])

# Required import
from ament_index_python.packages import get_package_share_directory
