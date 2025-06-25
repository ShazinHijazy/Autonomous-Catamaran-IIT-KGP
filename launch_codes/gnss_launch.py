from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',
            executable='gnss_node',
            name='gnss_node',
            output='screen',
            remappings=[('/fix', '/catamaran/gnss/fix')]
        )
    ])
