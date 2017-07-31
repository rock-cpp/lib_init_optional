#include "PositionProvider.hpp"

namespace log_replay {
    
using namespace init;

PositionProvider::PositionProvider(const std::string& taskName, const std::string& portName): 
    init::Base("ReplayPositionProvider"),
    init::PositionProvider("ReplayPositionProvider"),
    task(this, taskName),
    port(task, portName)
{
}

OutputProxyPort< base::samples::RigidBodyState >& PositionProvider::getPositionSamples()
{
    return port.getPort();
}

    
    
    
}

