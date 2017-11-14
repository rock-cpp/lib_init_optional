#pragma once
#include "../MotionControl2DProvider.hpp"
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"
#include <base/commands/Motion2D.hpp>

namespace log_replay
{

class GenericRawToMotion2D : public init::MotionControl2DProvider
{
    ReplayTask task;
    ReplayPort<base::commands::Motion2D> port;
public:
    GenericRawToMotion2D(const std::string& taskName, const std::string &portName);
    virtual OutputProxyPort<base::commands::Motion2D >& getCommand2DPort();
    
};

}

