#pragma once
#include "../PositionProvider.hpp"

namespace log_replay
{

class PositionProvider : public init::PositionProvider
{
    std::string taskName;
    std::string portName;
    OutputProxyPort< base::samples::RigidBodyState > *posPort;
    RTT::TaskContext *proxy;
public:
    PositionProvider(const std::string &taskName, const std::string &portName);
    virtual void initProxies();
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}
