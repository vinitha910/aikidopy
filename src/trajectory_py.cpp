#include "trajectory_py.hpp"
#include "state_space_py.hpp"
#include <pybind11/pybind11.h>
#include "aikido/trajectory/Trajectory.hpp"
#include "aikido/trajectory/Interpolated.hpp"

namespace py = pybind11;

namespace aikido {
namespace trajectory {
namespace python {

void Trajectory(py::module& m)
{
	py::class_<trajectory::Trajectory, std::shared_ptr<trajectory::Trajectory>>(m, "Trajectory");

	Interpolated(m);
}

void Interpolated(py::module& m)
{
	py::class_<trajectory::Interpolated, std::shared_ptr<trajectory::Interpolated>, trajectory::Trajectory>(m, "Interpolated")
		.def(py::init<statespace::ConstStateSpacePtr, statespace::ConstInterpolatorPtr>())
		.def("addWaypoint", 
			&trajectory::Interpolated::addWaypoint,
			py::arg("_t"),
			py::arg("_state"))
		.def("getStateSpace", &trajectory::Interpolated::getStateSpace);
}


}  // namesapce python
}  // namespace trajectory
}  // namesapce aikido