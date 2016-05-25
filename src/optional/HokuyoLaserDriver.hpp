#pragma once

#include <lib_init/LaserDriver.hpp>
#include <hokuyo/proxies/Task.hpp>
#include <laser_filter/proxies/Task.hpp>

namespace init
{

class HokuyoLaserDriver : public LaserDriver
{
public:
    HokuyoLaserDriver(const std::string &hokuyoTaskName, const std::string &filterTaskName);

    virtual bool connect();

    virtual OutputProxyPort< base::samples::LaserScan >& getLaserReadingsPort();
protected:
    DependentTask<hokuyo::proxies::Task> laserTask;
    DependentTask<laser_filter::proxies::Task> filterTask;
};
}
