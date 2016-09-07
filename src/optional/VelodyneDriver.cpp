#include "VelodyneDriver.hpp"


namespace init
{

VelodyneDriver::VelodyneDriver(const std::string &velodyneTaskName) : DepthMapProvider("VelodyneDriver"),
    velodyneTask(this, velodyneTaskName)
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
