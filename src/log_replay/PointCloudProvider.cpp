#include "PointCloudProvider.hpp"
namespace log_replay {
    
PointCloudProvider::PointCloudProvider(const std::string& Taskname, const std::string& portName): 
    init::PointCloudProvider("ReplayPointCloudProvider"),
    task(this, Taskname),
    port(task, portName)
{
    
}

void PointCloudProvider::initProxies()
{
    port.initPort();
    init::Base::initProxies();
}

OutputProxyPort< base::samples::Pointcloud >& PointCloudProvider::getPointCloudPort()
{
    return port.getPort();
}

    
    
}