#pragma once
#include "../ForceTorqueSensor.hpp"
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class ForceTorqueSensor : public init::ForceTorqueSensor
{
    ReplayTask task;
    ReplayPort<base::samples::Wrenches> port;
public:
    ForceTorqueSensor(const std::string &taskName, const std::string &portName);
    
    virtual OutputProxyPort< base::samples::Wrenches >& getStatusPort();  
};

}
