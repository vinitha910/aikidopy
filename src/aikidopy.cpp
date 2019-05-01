#include "distance_py.hpp"
#include "state_space_py.hpp"
#include "trajectory_py.hpp"
#include <pybind11/eigen.h>
#include <Eigen/Geometry>
#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace aikido {
namespace python {

PYBIND11_MODULE(aikidopy, m)
{
	Distance(m);
	statespace::python::StateSpaces(m);
	trajectory::python::Trajectory(m);
}

} // namespace python
} // namespace aikido