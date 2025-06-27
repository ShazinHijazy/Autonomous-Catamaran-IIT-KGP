from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_navigation',
            executable='return_to_base_node',
            name='return_to_base_node',
            output='screen',
            parameters=[],
            remappings=[
                ('/gnss/fix', '/fix'),          # Change if your GNSS topic is different
                ('/cmd_vel', '/cmd_vel'),       # Standard velocity command topic
                ('/heartbeat', '/heartbeat')    # Change if heartbeat is under a different namespace
            ]
        )
    ])
