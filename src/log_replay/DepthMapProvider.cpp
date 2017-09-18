#include "DepthMapProvider.hpp"

namespace log_replay {

DepthMapProvider::DepthMapProvider(const std::string& Taskname, const std::string& portName): 
    init::DepthMapProvider("ReplayDepthMapProvider"),
    task(this, Taskname),
    port(task, portName)
{

}

OutputProxyPort< base::samples::DepthMap >& DepthMapProvider::getDepthMapPort()
{
    return port.getPort();
}

    
    
    
}