cmake_minimum_required(VERSION 2.8.12)
project(aikidopy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Release)

find_package(catkin REQUIRED COMPONENTS pybind11_catkin)
find_package(aikido REQUIRED COMPONENTS statespace)
find_package(Eigen3 REQUIRED)

catkin_package(
  LIBRARIES
  CATKIN_DEPENDS pybind11_catkin
)

include_directories(${catkin_INCLUDE_DIRS})

pybind_add_module(state_space_py MODULE
    state_space_py.cpp
)

target_include_directories(state_space_py PUBLIC 
	${EIGEN3_INCLUDE_DIR} 
	${aikido_INCLUDE_DIRS}
)

target_link_libraries(state_space_py PUBLIC
  ${aikido_LIBRARIES}
  ${Eigen_LIBRARIES}
  ${PYTHON_LIBRARIES}
)