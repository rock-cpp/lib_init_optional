#pragma once
#include "../DepthMapProvider.hpp"
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class DepthMapProvider : public init::DepthMapProvider
{
    ReplayTask task;
    ReplayPort<base::samples::DepthMap> port;
public:
    DepthMapProvider(const std::string& Taskname, const std::string &portName);
    virtual OutputProxyPort< base::samples::DepthMap >& getDepthMapPort();
};

}


