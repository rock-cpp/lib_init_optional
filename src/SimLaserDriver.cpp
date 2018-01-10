#include "SimLaserDriver.hpp"
#include <mars/proxies/LaserRangeFinder.hpp>

namespace init
{

SimLaserDriver::SimLaserDriver(Simulator &sim, const std::string& taskName) 
    : LaserDriver("SimLaserDriver")
    , laserTask(DependentTask<mars::proxies::LaserRangeFinder>::getInstance(this, taskName))
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
