#pragma once

#include "../PointCloudProvider.hpp"
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class PointCloudProvider : public init::PointCloudProvider
{
    ReplayTask task;
    ReplayPort<base::samples::Pointcloud> port;
public:
    PointCloudProvider(const std::string& Taskname, const std::string &portName);
    virtual OutputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
};

}
