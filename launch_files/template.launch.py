import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration, Command
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch_ros.actions import Node

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler
from launch.conditions import IfCondition, UnlessCondition
from launch.event_handlers import OnProcessExit
from launch.substitutions import Command, FindExecutable, PathJoinSubstitution, LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare

import xacro

def generate_launch_description():

    # Declare arguments
    declared_arguments = []
    declared_arguments.append(
        DeclareLaunchArgument(
            "My_Param",
            default_value="Hello World",
            description="Example of a launch params",
        )
    )

    # Initialize Arguments
    my_param = LaunchConfiguration("My_Param")

    # YAML Params
    my_params = PathJoinSubstitution(
        [
            FindPackageShare("my_package"),
            "config",
            "my_params.yaml",
        ]
    )

    my_node = Node(
        package="my_package",
        executable="my_node",
        parameters=[my_params],
        remappings=[
            ("~/robot_description", "/robot_description"),
        ]
    )

    my_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(get_package_share_directory("my_package"), "launch", 
        "my_launch.launch.py"))
    )

    nodes = [
        my_node,
        my_launch
    ]

    return LaunchDescription(declared_arguments + nodes)
