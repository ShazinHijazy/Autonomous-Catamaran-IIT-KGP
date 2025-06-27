from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sensor_nodes',  # replace with your actual package name
            executable='logger_node',
            name='data_logger',
            output='screen'
        )
    ])
