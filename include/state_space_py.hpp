#include <pybind11/pybind11.h>

namespace aikido {
namespace statespace {
namespace python {

void StateSpaces(pybind11::module& m);
void StateSpace(pybind11::module& m);
void ScopedState(pybind11::module& m);
void StateHandle(pybind11::module& m);
void SE2(pybind11::module& m);
void Interpolator(pybind11::module& m);
void GeodesicInterpolator(pybind11::module& m);

}  // namesapce python
}  // namespace statespace
}  // namesapce aikido