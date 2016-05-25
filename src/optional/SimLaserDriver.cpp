#include "SimLaserDriver.hpp"

namespace init
{

SimLaserDriver::SimLaserDriver(Simulator &sim, const std::string& taskName) 
    : LaserDriver("SimLaserDriver")
    , laserTask(this, taskName, "mars::LaserRangeFinder")
{
    laserTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

void SimLaserDriver::initProxies()
{
    Base::initProxies();
    laserPort = new OutputProxyPort< base::samples::LaserScan >(laserTask.getProxy()->getPort("scans"));
}


OutputProxyPort< base::samples::LaserScan >& SimLaserDriver::getLaserReadingsPort()
{
    return *laserPort;
}
}
