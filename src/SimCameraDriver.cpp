#include "SimCameraDriver.hpp"
#include <mars/proxies/Camera.hpp>

namespace init
{
    
SimCameraDriver::SimCameraDriver(Simulator& sim, const std::string& taskName) : CameraDriver("SimCameraDriver")
    , cameraTask(DependentTask<mars::proxies::Camera>::getInstance(this, taskName))
{
    cameraTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

void SimCameraDriver::initProxies()
{
    init::Base::initProxies();
}

OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > >& SimCameraDriver::getFramePort()
{
    return cameraTask.getConcreteProxy()->frame;
}

}