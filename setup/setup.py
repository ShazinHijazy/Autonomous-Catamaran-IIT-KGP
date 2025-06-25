from setuptools import setup
import os
from glob import glob

package_name = 'catamaran_sensors'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    data_files=[
        # Install package.xml
        (os.path.join('share', package_name), ['package.xml']),
        # Install all launch files
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='you@example.com',
    description='ROS 2 Humble package for autonomous catamaran sensor integration',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'imu_node = catamaran_sensors.imu_node:main',
            'gnss_node = catamaran_sensors.gnss_node:main',
            'power_distribution_board_node = catamaran_sensors.power_distribution_board_node:main',
            'ultrasonic_servo_node = catamaran_sensors.ultrasonic_servo_node:main',
            'ultrasonic_waterproof_node = catamaran_sensors.ultrasonic_waterproof_node:main',
            'voltage_and_current_node = catamaran_sensors.voltage_and_current_node:main',
        ],
    },
)
