#include "SimLaserDriver.hpp"

namespace init
{

SimLaserDriver::SimLaserDriver(Simulator &sim, const std::string& taskName) 
    : LaserDriver("SimLaserDriver")
    , laserTask(this, taskName)
{
    laserTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

void SimLaserDriver::initProxies()
{
    Base::initProxies();
}


OutputProxyPort< base::samples::LaserScan >& SimLaserDriver::getLaserReadingsPort()
{
    return laserTask.getConcreteProxy()->scans;
}
}
