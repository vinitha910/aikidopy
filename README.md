# aikidopy
This catkin package contains python bindings for [aikido](https://github.com/personalrobotics/aikido). Note, not all classes/functions in aikido have been binded yet.

# Dependencies
Install [DART](https://dartsim.github.io/install_dart_on_ubuntu.html), [AIKIDO](https://github.com/personalrobotics/aikido) and the following dependencies:

```shell
$ sudo apt-get install ros-<DISTRO>-rospy ros-<DISTRO>-pybind11-catkin libeigen3-dev python-catkin-tools python-catkin-pkg
```

Replace `DISTRO` with the correct ROS distribution.

# Usage
Clone this package into a catkin workspace and build the workspace:

```shell
$ mkdir catkin_ws
$ cd catkin_ws && mkdir src $$ cd src
$ catkin_init_workspace
$ git clone https://github.com/vinitha910/aikidopy.git
< CLONE OTHER NECESSARY REPOSITORIES >
$ cd ~/catkin_ws
$ catkin build
$ source devel/setup.bash
```

You shoud now be able to load `aikidopy` in python:
```shell
$ python
>>> import aikidopy
```
