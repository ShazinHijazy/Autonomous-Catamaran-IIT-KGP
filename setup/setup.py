from setuptools import setup
import os
from glob import glob

package_name = 'catamaran_ros'

setup(
    name=package_name,
    version='1.0.0',
    packages=[package_name],
    data_files=[
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'rviz'), glob('rviz/*.rviz')),
        (os.path.join('share', package_name, 'maps'), glob('maps/*')),
        (os.path.join('share', package_name, 'config'), glob('config/*.yaml')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Shazin Hijazy',
    maintainer_email='shazhijazy@gmail.com',
    description='Complete ROS 2 Humble-based system for controlling and navigating an autonomous catamaran using integrated sensors, thruster control, obstacle avoidance, and telemetry.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # Sensor Nodes
            'imu_node = catamaran_ros.imu_node:main',
            'gnss_node = catamaran_ros.gnss_node:main',
            'ultrasonic_waterproof_node = catamaran_ros.ultrasonic_waterproof_node:main',
            'ultrasonic_node = catamaran_ros.ultrasonic_node:main',
            #'voltage_and_current_node = catamaran_ros.voltage_and_current_node:main',
            #'power_distribution_board_node = catamaran_ros.power_distribution_board_node:main',

            # Thruster Control
            'thruster_control = catamaran_ros.thruster_control:main',
            'teleop_thruster = catamaran_ros.teleop_thruster:main',
            'pwm_output = catamaran_ros.pwm_output:main',

            # Telemetry & Failsafe
            'telemetry_node = catamaran_ros.telemetry_node:main',
            'fail_safe_return_node = catamaran_ros.fail_safe_return_node:main',

            # Obstacle Avoidance
            'obstacle_avoidance_node = catamaran_ros.obstacle_avoidance_node:main',
        ],
    },
)
