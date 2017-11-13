#include "VelodyneDriver.hpp"
#include <velodyne_lidar/proxies/LaserScanner.hpp>


namespace init
{

VelodyneDriver::VelodyneDriver(const std::string &velodyneTaskName) : DepthMapProvider("VelodyneDriver"),
    velodyneTask(DependentTask< velodyne_lidar::proxies::LaserScanner >::getInstance(this, velodyneTaskName))
{

}

bool VelodyneDriver::connect()
{
    return init::DepthMapProvider::connect();
}


OutputProxyPort< base::samples::DepthMap >& VelodyneDriver::getLaserScansPort()
{
    return getDepthMapPort();
}

OutputProxyPort< base::samples::DepthMap >& VelodyneDriver::getDepthMapPort()
{
    return velodyneTask.getConcreteProxy()->laser_scans;
}

}
