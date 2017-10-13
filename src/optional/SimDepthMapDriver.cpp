#include "SimDepthMapDriver.hpp"

namespace init
{

SimDepthMapDriver::SimDepthMapDriver(Simulator& sim, const std::string& velodyneTaskName) : DepthMapProvider("SimDepthMapDriver"),
    velodyneTask(this, velodyneTaskName)
{
    velodyneTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

SimDepthMapDriver::~SimDepthMapDriver()
{

}

void SimDepthMapDriver::initProxies()
{
    DepthMapProvider::initProxies();
    simulatedDepthMapPort = new OutputProxyPort< base::samples::DepthMap >(velodyneTask.getProxy()->getPort("laser_scans"));
}

OutputProxyPort< base::samples::DepthMap >& SimDepthMapDriver::getDepthMapPort()
{
    return *simulatedDepthMapPort;
}

}