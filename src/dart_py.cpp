#include <dart_py.hpp>
#include "dart/dynamics/Skeleton.hpp"

namespace py = pybind11;

namespace dart {
namespace dynamics {
namespace python {

void DART(py::module& m)
{
	Skeleton(m);
}

void Skeleton(py::module& m)
{
	py::class_<dynamics::Skeleton, std::shared_ptr<dynamics::Skeleton>>(m, "Skeleton");
}

}  // namespace python
}  // namespace dynamics
}  // namesapce dart