from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',
            executable='ultrasonic_servo_node',
            name='ultrasonic_servo_node',
            output='screen',
            parameters=[
                {'trigger_pin': 17, 'echo_pin': 27, 'servo_pin': 18, 'scan_angle': 90, 'step_angle': 10}
            ],
            remappings=[
                ('/ultrasonic/scan', '/catamaran/ultrasonic/rotating_scan')
            ]
        )
    ])
