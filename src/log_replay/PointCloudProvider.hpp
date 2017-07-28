#pragma once

#include "../PointCloudProvider.hpp"

namespace log_replay
{

class PointCloudProvider : public init::PointCloudProvider
{
    std::string taskName;
    std::string portName;
    
    RTT::TaskContext *proxy;
    OutputProxyPort< base::samples::Pointcloud > *port;
    
public:
    PointCloudProvider(const std::string& Taskname, const std::string &portName);
    virtual void initProxies();
    virtual OutputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
};

}
