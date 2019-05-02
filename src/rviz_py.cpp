#include "rviz_py.hpp"
#include "dart_py.hpp"
#include <pybind11/pybind11.h>
#include "aikido/rviz/InteractiveMarkerViewer.hpp"
#include "aikido/rviz/ResourceServer.hpp"
#include "aikido/rviz/SkeletonMarker.hpp"
#include <interactive_markers/interactive_marker_server.h>

namespace aikido {
namespace rviz {
namespace python {

void Rviz(py::module& m)
{
	InteractiveMarkerViewer(m);
	ResourceServer(m);
	SkeletonMarker(m);
}

void InteractiveMarkerViewer(py::module& m)
{
	py::class_<rviz::InteractiveMarkerViewer>(m, "InteractiveMarkerViewer")
		.def(py::init<const std::string&, const std::string&>())
		.def("addSkeleton", &InteractiveMarkerViewer::addSkeleton, py::arg("skeleton"))
		.def("setAutoUpdate", &InteractiveMarkerViewer::setAutoUpdate, py::arg("flag"));
}

void ResourceServer(py::module& m)
{
	py::class_<rviz::ResourceServer>(m, "ResourceServer")
		.def(py::init<>());
}

void SkeletonMarker(py::module& m)
{
	// import interactive_markers.interactive_marker_server
	py::object InteractiveMarkerServer = py::module::import("interactive_markers.interactive_marker_server");

	py::class_<rviz::SkeletonMarker, std::shared_ptr<rviz::SkeletonMarker>>(m, "SkeletonMarker")
		.def(py::init<
			rviz::ResourceServer*, 
			interactive_markers::InteractiveMarkerServer*,
			const dart::dynamics::WeakSkeletonPtr&,
			const std::string&>());
}

}  // namesapce python
}  // namespace statespace
}  // namesapce aikido