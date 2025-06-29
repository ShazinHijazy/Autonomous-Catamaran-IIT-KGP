from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import os

def generate_launch_description():
    pkg_share = FindPackageShare('catamaran_ros').find('catamaran_ros')
    urdf_path = os.path.join(pkg_share, 'urdf', 'catamaran.urdf')
    nav2_params_path = os.path.join(pkg_share, 'config', 'nav2_params.yaml')
    ekf_config_path = os.path.join(pkg_share, 'config', 'ekf.yaml')

    with open(urdf_path, 'r') as infp:
        robot_description = infp.read()

    return LaunchDescription([
        # Robot State Publisher (TF tree)
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': robot_description}]
        ),
        # EKF Node for Odometry Fusion
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            output='screen',
            parameters=[ekf_config_path]
        ),
        # NavSat Transform Node for GNSS+IMU fusion
        Node(
            package='robot_localization',
            executable='navsat_transform_node',
            name='navsat_transform_node',
            output='screen',
            parameters=[ekf_config_path]
        ),
        # Nav2 Bringup
        Node(
            package='nav2_bringup',
            executable='bringup_launch.py',
            output='screen',
            parameters=[nav2_params_path]
        ),
        # Optionally add your sensor nodes here if not started elsewhere
    ])
