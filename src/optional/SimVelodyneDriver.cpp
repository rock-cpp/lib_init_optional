#include "SimVelodyneDriver.hpp"

namespace init
{

SimVelodyneDriver::SimVelodyneDriver(Simulator &sim, const std::string& velodyneTaskName) : PointCloudProvider("SimVelodyneDriver"),
    velodyneTask(this, velodyneTaskName)
{
    velodyneTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

SimVelodyneDriver::~SimVelodyneDriver()
{

}

void SimVelodyneDriver::initProxies()
{
    Base::initProxies();
    simulatedPointcloudPort = new OutputProxyPort< base::samples::Pointcloud >(velodyneTask.getProxy()->getPort("pointcloud"));
}

OutputProxyPort< base::samples::Pointcloud >& SimVelodyneDriver::getPointCloudPort()
{
    return *simulatedPointcloudPort;
}

}
