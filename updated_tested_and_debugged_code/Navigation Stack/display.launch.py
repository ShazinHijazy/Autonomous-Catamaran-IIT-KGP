from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
import os

def generate_launch_description():
    # Get the path to the URDF/Xacro file
    pkg_share = os.path.join(
        os.path.expanduser('~'),
        'catamaran_ws', 'src', 'catamaran_description'
    )
    urdf_file = os.path.join(pkg_share, 'urdf', 'catamaran.urdf.xacro')

    return LaunchDescription([
        # Joint State Publisher GUI (for interactive joint control, optional for fixed robots)
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui',
            output='screen'
        ),
        # Robot State Publisher (publishes TF and robot_description)
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            arguments=[urdf_file]
        ),
        # Optionally, launch RViz2 with a blank config
        ExecuteProcess(
            cmd=['rviz2', '-d', ''],
            output='screen'
        )
    ])
