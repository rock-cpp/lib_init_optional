#pragma once
#include <lib_init/JointDriver.hpp>
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class JointDriver : public init::JointDriver
{
    ReplayTask task;
    ReplayPort<base::samples::Joints> port;
public :
    JointDriver(const std::string& taskName, const std::string& portName);
    
    virtual InputProxyPort< base::commands::Joints >& getCommandPort();
    virtual OutputProxyPort< base::samples::Joints >& getStatusPort();
};

}

