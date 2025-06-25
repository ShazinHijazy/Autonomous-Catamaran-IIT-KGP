from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sensor_nodes',
            executable='imu_node',
            name='imu_node',
            output='screen'
        ),
        Node(
            package='sensor_nodes',
            executable='gnss_node',
            name='gnss_node',
            output='screen'
        ),
        Node(
            package='sensor_nodes',
            executable='rplidar_launch',
            name='rplidar_node',
            output='screen'
        ),
        Node(
            package='sensor_nodes',
            executable='ultrasonic_waterproof_node',
            name='ultrasonic_waterproof_node',
            output='screen'
        ),
        Node(
            package='sensor_nodes',
            executable='ultrasonic_servo_node',
            name='ultrasonic_servo_node',
            output='screen'
        ),
        Node(
            package='sensor_nodes',
            executable='power_distribution_board_node',
            name='power_distribution_board_node',
            output='screen'
        ),
        Node(
            package='sensor_nodes',
            executable='voltage_and_current_node',
            name='voltage_and_current_node',
            output='screen'
        ),
    ])
