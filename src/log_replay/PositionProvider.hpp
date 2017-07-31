#pragma once
#include "../PositionProvider.hpp"
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class PositionProvider : public init::PositionProvider
{
    ReplayTask task;
    ReplayPort<base::samples::RigidBodyState > port;
public:
    PositionProvider(const std::string &taskName, const std::string &portName);
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}
