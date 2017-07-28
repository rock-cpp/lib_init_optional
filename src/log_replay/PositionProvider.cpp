#include "PositionProvider.hpp"

namespace log_replay {
    
using namespace init;

PositionProvider::PositionProvider(const std::string& taskName, const std::string& portName): 
    init::Base("ReplayPositionProvider"),
    init::PositionProvider("ReplayPositionProvider"),
    taskName(taskName),
    portName(portName)
{
}

void PositionProvider::initProxies()
{
    proxy = RTT::corba::TaskContextProxy::Create(taskName);
    posPort = new OutputProxyPort< base::samples::RigidBodyState>(proxy, portName);
    
    init::Base::initProxies();
}


OutputProxyPort< base::samples::RigidBodyState >& PositionProvider::getPositionSamples()
{
    return *posPort;
}

    
    
    
}

