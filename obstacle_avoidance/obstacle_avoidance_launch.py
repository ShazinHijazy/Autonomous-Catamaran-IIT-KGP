import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',
            executable='obstacle_avoidance_node',
            name='obstacle_avoidance_node',
            output='screen',
            parameters=[
                {'min_safe_distance': 0.5},  # meters
                {'lidar_topic': '/scan'},
                {'ultrasonic_front_topic': '/ultrasonic_front/range'},
                {'ultrasonic_side_topic': '/ultrasonic_side/range'}
            ],
            remappings=[
                # Optional: adjust topics based on actual names
                ('/scan', '/scan'),
                ('/ultrasonic_front/range', '/ultrasonic_front/range'),
                ('/ultrasonic_side/range', '/ultrasonic_side/range')
            ]
        )
    ])
