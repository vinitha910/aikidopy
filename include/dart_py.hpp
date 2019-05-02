#include <pybind11/pybind11.h>

namespace dart {
namespace dynamics {
namespace python {

void DART(pybind11::module& m);
void Skeleton(pybind11::module& m);

}  // namespace python
}  // namespace dynamics
}  // namesapce dart