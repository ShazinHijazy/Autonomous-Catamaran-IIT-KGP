from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='catamaran_system',  # 🔁 Change to your actual package name
            executable='telemetry_bridge_node',
            name='telemetry_bridge',
            output='screen',
            emulate_tty=True,  # 👈 Enables color logs
            parameters=[]      # Add if needed
        )
    ])
