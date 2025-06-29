from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    # Update these paths for your project directory structure
    urdf_file = os.path.join(
        os.getenv('HOME'),
        'catamaran_ws',
        'src',
        'catamaran_description',
        'urdf',
        'catamaran.urdf.xacro'
    )
    slam_params_file = os.path.join(
        os.getenv('HOME'),
        'catamaran_ws',
        'src',
        'catamaran_navigation',
        'config',
        'slam_toolbox_params.yaml'
    )

    return LaunchDescription([
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            arguments=[urdf_file],
            output='screen'
        ),
        Node(
            package='slam_toolbox',
            executable='async_slam_toolbox_node',
            name='slam_toolbox',
            output='screen',
            parameters=[slam_params_file]
        ),
        # Add your sensor driver nodes here if needed
    ])
