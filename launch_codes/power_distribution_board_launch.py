from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',
            executable='power_distribution_board_node',
            name='pdb_node',
            output='screen',
            remappings=[
                ('/pdb/voltage', '/catamaran/pdb/voltage'),
                ('/pdb/current', '/catamaran/pdb/current')
            ]
        )
    ])
