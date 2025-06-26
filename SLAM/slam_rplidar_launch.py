from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # SLAM Toolbox (real-time mapping)
        Node(
            package='slam_toolbox',
            executable='sync_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[{'use_sim_time': False}]
        ),

        # RPLidar Node
        Node(
            package='rplidar_ros',
            executable='rplidarNode',  # Change to rplidar_composition if using source build
            name='rplidar',
            output='screen',
            parameters=[
                {'serial_port': '/dev/ttyUSB0'},  # Confirm with ls /dev/
                {'frame_id': 'laser_frame'}
            ]
        )
    ])
