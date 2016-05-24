#include "VelodyneDriver.hpp"

#include <velodyne_lidar/proxies/LaserScanner.hpp>

namespace init
{

VelodyneDriver::VelodyneDriver(const std::string &velodyneTaskName) : Base("VelodyneDriver"),
    velodyneTask(this, velodyneTaskName, "velodyne_lidar::LaserScanner")
{

}

bool VelodyneDriver::connect()
{
    return init::Base::connect();
}


OutputProxyPort< base::samples::DepthMap >& VelodyneDriver::getLaserScansPort()
{
    return velodyneTask.getConcreteProxy()->laser_scans;
}

}
