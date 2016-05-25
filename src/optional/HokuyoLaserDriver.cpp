#include "HokuyoLaserDriver.hpp"

namespace init
{

HokuyoLaserDriver::HokuyoLaserDriver(const std::string &hokuyoTaskName, const std::string &filterTaskName) : LaserDriver("HokuyoLaserDriver"), laserTask(this, hokuyoTaskName, "hokuyo::Task"), filterTask(this, filterTaskName, "laser_filter::Task")
{

}

bool HokuyoLaserDriver::connect()
{
    laserTask.getConcreteProxy()->scans.connectTo(filterTask.getConcreteProxy()->scan_samples, RTT::ConnPolicy::buffer(50));
    return init::Base::connect();
}


OutputProxyPort< base::samples::LaserScan >& HokuyoLaserDriver::getLaserReadingsPort()
{
    return filterTask.getConcreteProxy()->filtered_scans;
}

}
