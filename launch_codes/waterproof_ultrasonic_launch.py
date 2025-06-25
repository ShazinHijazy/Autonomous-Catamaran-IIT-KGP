from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',
            executable='ultrasonic_waterproof_node',
            name='ultrasonic_waterproof_node',
            output='screen',
            parameters=[
                {'trigger_pin': 22, 'echo_pin': 23}
            ],
            remappings=[
                ('/ultrasonic/distance', '/catamaran/ultrasonic/static')
            ]
        )
    ])
