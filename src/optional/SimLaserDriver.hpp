#pragma once

#include <lib_init/LaserDriver.hpp>
#include <mars/proxies/LaserRangeFinder.hpp>
#include "Simulator.hpp"

namespace init
{

class SimLaserDriver : public LaserDriver
{
public:
    SimLaserDriver(Simulator &sim, const std::string &taskName);

    virtual void initProxies();

    virtual OutputProxyPort< base::samples::LaserScan >& getLaserReadingsPort();
protected:
    DependentTask<mars::proxies::LaserRangeFinder> laserTask;
};
}
