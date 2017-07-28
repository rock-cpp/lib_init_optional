#include "PointCloudProvider.hpp"
namespace log_replay {
    
PointCloudProvider::PointCloudProvider(const std::string& Taskname, const std::string& portName): 
    init::PointCloudProvider("ReplayPointCloudProvider"),
    taskName(Taskname),
    portName(portName)
{
    
}

void PointCloudProvider::initProxies()
{
    proxy = RTT::corba::TaskContextProxy::Create(taskName);
    
    port = new OutputProxyPort< base::samples::Pointcloud >(proxy, portName);
    init::Base::initProxies();
}

OutputProxyPort< base::samples::Pointcloud >& PointCloudProvider::getPointCloudPort()
{
    return *port;
}

    
    
}