#include "SimCameraDriver.hpp"

namespace init
{
    
SimCameraDriver::SimCameraDriver(Simulator& sim, const std::string& taskName) : CameraDriver("SimCameraDriver"), cameraTask(this, taskName, "mars::Camera")
{
    cameraTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

void SimCameraDriver::initProxies()
{
    init::Base::initProxies();
    framePort = new OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > >(cameraTask.getProxy()->getPort("frame"));
}

OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > >& SimCameraDriver::getFramePort()
{
    return *framePort;
}

}