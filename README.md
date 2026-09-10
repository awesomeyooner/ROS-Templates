[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![ubuntu24](https://img.shields.io/badge/-UBUNTU_24.04-orange?style=flat-square&logo=ubuntu&logoColor=white)](https://releases.ubuntu.com/jammy/)
[![humble](https://img.shields.io/badge/-jazzy-blue?style=flat-square&logo=ros)](https://docs.ros.org/en/humble/index.html)

# ROS-Templates
A bunch of ROS 2 Packages that serve as barebones templates

## Notes

### Working with VSCode

When using VSCode, to make CMake the intellisense provider, use

1. `Ctrl + Shift + P`
2. `C/C++: Change Configuration Provider`
3. `CMake Tools`

You can force this by editting `/.vscode/settings.json`

```json

{
    "cmake.sourceDirectory": "/home/user/ros2_ws/src/my_package",
    "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools"
}
```

Change the path for `"cmake.sourceDirectory": "/home/user/ros2_ws/src/my_package"` to your actual package

Additionally, you can use `compile_commands`

`/.vscode/c_cpp_properties.json`

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "/opt/ros/humble/include/rclcpp/rclcpp",
                "/opt/ros/humble/include/rclcpp",
                "/opt/ros/humble/include/**",,
                "${workspaceFolder}/src",
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64",
            "compileCommands": "${workspaceFolder}/build/compile_commands.json"
        }
    ],
    "version": 4
}
```

The key line is the `"compileCommands": "${workspaceFolder}/build/compile_commands.json"`


## Folder Directory

- `custom_controller` ros2_control based custom controller
- `robot_hardware` ros2_control Hardware Interface