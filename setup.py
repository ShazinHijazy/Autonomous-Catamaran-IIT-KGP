from setuptools import setup

package_name = 'catamaran_thruster_control'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Jaswanth',
    maintainer_email='jaswanth@ubuntu-22',
    description='Custom ROS 2 teleop with speed control, HUD, and logging for catamaran control',
    license='MITApache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'custom_teleop = catamaran_thruster_control.custom_teleop:main',
        ],
    },
)
