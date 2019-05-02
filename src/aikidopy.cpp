#include "dart_py.hpp"
#include "state_space_py.hpp"
#include "trajectory_py.hpp"
#include "rviz_py.hpp"
#include <pybind11/eigen.h>
#include <Eigen/Geometry>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace aikido {
namespace python {

PYBIND11_MODULE(aikidopy, m)
{
	dart::dynamics::python::DART(m);
	statespace::python::StateSpaces(m);
	trajectory::python::Trajectory(m);
	rviz::python::Rviz(m);
}

} // namespace python
} // namespace aikido