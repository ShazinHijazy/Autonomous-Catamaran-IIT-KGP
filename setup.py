from setuptools import setup

package_name = 'catamaran_thruster_control'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Your Name',
    maintainer_email='your@email.com',
    description='Custom teleop for ROS 2 catamaran',
    license='Apache License 2.0',
    entry_points={
        'console_scripts': [
            'custom_teleop = catamaran_thruster_control.custom_teleop:main',
        ],
    },
)
