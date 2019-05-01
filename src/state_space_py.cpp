#include <state_space_py.hpp>
#include <distance_py.hpp>
#include <pybind11/eigen.h>
#include <Eigen/Geometry>
#include "aikido/distance/DistanceMetric.hpp"
#include "aikido/statespace/StateHandle.hpp"
#include "aikido/statespace/StateSpace.hpp"
#include "aikido/statespace/ScopedState.hpp"
#include "aikido/statespace/SE2.hpp"

namespace py = pybind11;

namespace aikido {
namespace statespace {
namespace python {

using StateSpacePy = statespace::StateSpace;
using StateHandlePy = statespace::StateHandle<StateSpacePy, StateSpacePy::State>;
using ScopedStatePy = statespace::ScopedState<StateHandlePy>;
using Isometry2d
        = Eigen::Transform<double, 2, Eigen::Isometry, Eigen::DontAlign>;

void StateSpace(pybind11::module& m)
{
	StateSpacePyBind(m);
	ScopedStatePyBind(m);
	StateHandlePyBind(m);
	SE2PyBind(m);
}

void StateSpacePyBind(pybind11::module& m)
{
	py::class_<StateSpacePy>(m, "StateSpace")
		.def("createState", &StateSpacePy::createState)
		.def("cloneState", &StateSpacePy::cloneState, py::arg("stateIn"));

	py::class_<StateSpacePy::State, std::unique_ptr<StateSpacePy::State, py::nodelete>>(m, "StateSpaceState");
}

void ScopedStatePyBind(pybind11::module& m)
{
	py::class_<ScopedStatePy>(m, "ScopedState")
		.def(py::init<const StateSpacePy*>())
		.def("clone", &ScopedStatePy::clone);
}

void StateHandlePyBind(pybind11::module& m)
{
	py::class_<StateHandlePy>(m, "StateHandle")
		.def(py::init<>());
}

void SE2PyBind(pybind11::module& m)
{
	py::class_<statespace::SE2, StateSpacePy>(m, "SE2")
		.def("createState", &statespace::SE2::createState)
		.def("cloneState", &statespace::SE2::cloneState, py::arg("stateIn"));

	py::class_<statespace::SE2::State, StateSpacePy::State>(m, "SE2State")
		.def(py::init<>())
		.def(py::init([](const Isometry2d& _transform) {
			return statespace::SE2::State(_transform);
		}))
		.def("setIsometry", &statespace::SE2::State::setIsometry, py::arg("_transform"))
		.def("getIsometry", &statespace::SE2::State::getIsometry, py::return_value_policy::reference_internal);
}

}  // python
}  // namespace statespace
}  // namesapce aikido