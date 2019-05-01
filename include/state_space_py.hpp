#include <pybind11/pybind11.h>

namespace aikido {
namespace statespace {
namespace python {

void StateSpace(pybind11::module& m);
void StateSpacePyBind(pybind11::module& m);
void ScopedStatePyBind(pybind11::module& m);
void StateHandlePyBind(pybind11::module& m);
void SE2PyBind(pybind11::module& m);

}  // namesapce python
}  // namespace statespace
}  // namesapce aikido