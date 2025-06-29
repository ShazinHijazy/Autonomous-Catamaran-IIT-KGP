from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    pkg_dir = os.path.expanduser('~/catamaran_ws/src/catamaran_navigation')
    urdf_file = os.path.expanduser('~/catamaran_ws/src/catamaran_description/urdf/catamaran.urdf.xacro')
    map_file = os.path.join(pkg_dir, 'maps', 'my_map.yaml')
    nav2_params = os.path.join(pkg_dir, 'config', 'nav2_params.yaml')

    return LaunchDescription([
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            arguments=[urdf_file],
            output='screen'
        ),
        Node(
            package='nav2_bringup',
            executable='bringup_launch.py',
            output='screen',
            parameters=[nav2_params],
            arguments=[
                f'map:={map_file}',
                'use_sim_time:=false'
            ]
        ),
        # Add sensor nodes here if not launched elsewhere
    ])
