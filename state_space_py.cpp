#include <pybind11/pybind11.h>
#include "aikido/statespace/StateHandle.hpp"
#include "aikido/statespace/StateSpace.hpp"

namespace py = pybind11;

namespace aikido {
namespace statespace {

PYBIND11_MODULE(state_space_py, m)
{
	py::class_<StateSpace>(m, "StateSpace")
		.def("createState", &StateSpace::createState);

	py::class_<StateSpace::State, std::unique_ptr<StateSpace::State, py::nodelete>>(m, "State");

	py::class_<StateHandle<StateSpace, StateSpace::State>>(m, "StateHandle")
		.def(py::init<>());
		// .def(py::init<StateHandle::StateSpace &, StateHandle::QualifiedState &>());
		
		// .def("getCozmoSkeleton", &Cozmo::getCozmoSkeleton)
		// .def("setForkliftPosition", &Cozmo::setForkliftPosition, py::arg("pos"))
		// .def("createState", &Cozmo::createState, py::arg("x"), py::arg("y"), py::arg("th"));
}

}  // namespace statespace
}  // namesapce aikido