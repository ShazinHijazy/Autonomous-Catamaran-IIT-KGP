from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, GroupAction
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition, UnlessCondition
from launch_ros.actions import Node

def generate_launch_description():
    # Define the mode argument (teleop or autonomous)
    mode_arg = DeclareLaunchArgument(
        'mode',
        default_value='autonomous',
        description='Choose control mode: teleop or autonomous'
    )

    # Launch teleop control nodes if mode == teleop
    teleop_group = GroupAction([
        Node(
            package='thruster_control',
            executable='thruster_teleop',
            name='thruster_teleop_node',
            output='screen',
            condition=IfCondition(LaunchConfiguration('mode') == 'teleop')
        ),
        Node(
            package='thruster_control',
            executable='pwm_output_node',
            name='pwm_output_node_teleop',
            output='screen',
            parameters=[
                {'left_thruster_pin': 18},
                {'right_thruster_pin': 19}
            ],
            condition=IfCondition(LaunchConfiguration('mode') == 'teleop')
        )
    ])

    # Launch autonomous control nodes if mode == autonomous
    autonomous_group = GroupAction([
        Node(
            package='thruster_control',
            executable='thruster_control',
            name='thruster_control_node',
            output='screen',
            condition=IfCondition(LaunchConfiguration('mode') == 'autonomous')
        ),
        Node(
            package='thruster_control',
            executable='pwm_output_node',
            name='pwm_output_node_auto',
            output='screen',
            parameters=[
                {'left_thruster_pin': 18},
                {'right_thruster_pin': 19}
            ],
            condition=IfCondition(LaunchConfiguration('mode') == 'autonomous')
        )
    ])

    return LaunchDescription([
        mode_arg,
        teleop_group,
        autonomous_group
    ])
