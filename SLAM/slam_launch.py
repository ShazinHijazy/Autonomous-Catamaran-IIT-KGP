from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # SLAM Toolbox - live mapping
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[
                {'use_sim_time': False}
            ]
        ),

        # RPLidar Node
        Node(
            package='rplidar_ros',
            executable='rplidarNode',  # <- More common name
            name='rplidar',
            output='screen',
            parameters=[
                {'serial_port': '/dev/ttyUSB0'},  # Confirm with dmesg
                {'frame_id': 'laser_frame'}
            ],
            remappings=[
                ('/scan', '/scan')  # Match what SLAM expects
            ]
        )
    ])
