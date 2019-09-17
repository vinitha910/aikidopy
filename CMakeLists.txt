cmake_minimum_required(VERSION 3.0)
project(aikidopy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)

set(PYBIND11_PYTHON_VERSION 3.5)
find_package(PythonInterp 3.5 REQUIRED)
find_package(PythonLibs 3.5 REQUIRED)

find_package(catkin REQUIRED COMPONENTS pybind11_catkin rospy)
find_package(aikido REQUIRED COMPONENTS statespace trajectory rviz)
find_package(Eigen3 REQUIRED)

catkin_package(
  	LIBRARIES
  	CATKIN_DEPENDS pybind11_catkin
)

include_directories(
	${catkin_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR} 
	include
)

set(aikidopy_headers
	include/dart_py.hpp
	include/state_space_py.hpp
	include/trajectory_py.hpp
	include/rviz_py.hpp
)
set(aikidopy_sources
	src/dart_py.cpp
	src/state_space_py.cpp
	src/trajectory_py.cpp
	src/rviz_py.cpp
	src/aikidopy.cpp
)

pybind_add_module(aikidopy MODULE
    ${aikidopy_headers}
    ${aikidopy_sources}
)
target_include_directories(aikidopy PUBLIC 
	${EIGEN3_INCLUDE_DIR} 
	${aikido_INCLUDE_DIRS}
)
target_link_libraries(aikidopy PUBLIC
  	${aikido_LIBRARIES}
 	${Eigen_LIBRARIES}
  	${PYTHON_LIBRARIES}
)