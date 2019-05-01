#include <pybind11/pybind11.h>

namespace aikido {
namespace trajectory {
namespace python {

void Trajectory(pybind11::module& m);
void Interpolated(pybind11::module& m);

}  // namesapce python
}  // namespace trajectory
}  // namesapce aikido