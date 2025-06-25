from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_sensors',
            executable='voltage_and_current_node',
            name='voltage_current_node',
            output='screen',
            remappings=[
                ('/voltage', '/catamaran/pdb/voltage'),
                ('/current', '/catamaran/pdb/current')
            ]
        )
    ])
