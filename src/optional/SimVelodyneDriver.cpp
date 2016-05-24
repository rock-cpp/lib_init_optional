#include "SimVelodyneDriver.hpp"

namespace init
{

SimVelodyneDriver::SimVelodyneDriver(Simulator &sim, const std::string& velodyneTaskName) : Base("SimVelodyneDriver"),
    velodyneTask(this, velodyneTaskName, "mars::RotatingLaserRangeFinder")
{
    velodyneTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

void SimVelodyneDriver::initProxies()
{
    Base::initProxies();
    simulatedPointcloudPort = new OutputProxyPort< base::samples::Pointcloud >(velodyneTask.getProxy()->getPort("pointcloud"));
}

OutputProxyPort< base::samples::Pointcloud >& SimVelodyneDriver::getSimulatedPointcloudPort()
{
    return *simulatedPointcloudPort;
}

}