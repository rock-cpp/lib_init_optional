#pragma once

#include <lib_init/LaserDriver.hpp>
#include <lib_init/Simulator.hpp>

namespace init
{

class SimLaserDriver : public LaserDriver
{
public:
    SimLaserDriver(Simulator &sim, const std::string &taskName);

    virtual void initProxies();

    virtual OutputProxyPort< base::samples::LaserScan >& getLaserReadingsPort();
protected:
    DependentTaskBase laserTask;
    OutputProxyPort< base::samples::LaserScan > *laserPort;
};
}
