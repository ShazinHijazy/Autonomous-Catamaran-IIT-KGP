from setuptools import setup

package_name = 'catamaran_thruster_control'

setup(
    name=package_name,
    version='0.1.0',
    packages=[package_name],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Shazin',
    maintainer_email='shazhijazy@gmail.com',
    description='ROS 2 package for catamaran thruster control',
    license='MIT',
    entry_points={
        'console_scripts': [
            'thruster_controller = thruster_controller:main',
        ],
    },
)
