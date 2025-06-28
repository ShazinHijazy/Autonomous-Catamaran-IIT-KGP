from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='autonomous_catamaran',
            executable='gnss_node',
            name='gnss_node',
            output='screen',
            parameters=[],
            remappings=[
                # Optional: remap if needed
                # ('fix', '/gps/fix')
            ]
        )
    ])