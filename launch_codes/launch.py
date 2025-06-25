from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    # Assuming your package is named 'catamaran_sensors'
    pkg_path = get_package_share_directory('catamaran_sensors')

    # Absolute path to the rplidar launch file
    rplidar_launch = os.path.join(pkg_path, 'rplidar_launch.py')

    return LaunchDescription([

        # IMU Node
        Node(
            package='catamaran_sensors',
            executable='imu_node',
            name='imu_node',
            output='screen',
            emulate_tty=True,
        ),

        # GNSS Node
        Node(
            package='catamaran_sensors',
            executable='gnss_node',
            name='gnss_node',
            output='screen',
            emulate_tty=True,
        ),

        # Ultrasonic Waterproof Node
        Node(
            package='catamaran_sensors',
            executable='ultrasonic_waterproof_node',
            name='ultrasonic_waterproof_node',
            output='screen',
            emulate_tty=True,
        ),

        # Ultrasonic Rotating Servo Node
        Node(
            package='catamaran_sensors',
            executable='ultrasonic_servo_node',
            name='ultrasonic_servo_node',
            output='screen',
            emulate_tty=True,
        ),

        # RPLidar Launch File (included properly)
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(rplidar_launch)
        ),

        # Voltage & Current Node
        Node(
            package='catamaran_sensors',
            executable='voltage_and_current_node',
            name='voltage_and_current_node',
            output='screen',
            emulate_tty=True,
        ),

        # Power Distribution Board Monitor
        Node(
            package='catamaran_sensors',
            executable='power_distribution_board_node',
            name='power_distribution_board_node',
            output='screen',
            emulate_tty=True,
        ),
    ])
