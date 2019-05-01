#include <distance_py.hpp>
#include "aikido/distance/DistanceMetric.hpp"

namespace py = pybind11;

namespace aikido {
namespace python {

void Distance(pybind11::module& m)
{
	py::class_<distance::DistanceMetric>(m, "DistanceMetric");
}

}  // namespace statespace
}  // namesapce aikido