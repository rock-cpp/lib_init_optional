#include "ForceTorqueSensor.hpp"

namespace log_replay {
    
ForceTorqueSensor::ForceTorqueSensor(const std::string& taskName, const std::string& portName):
    init::ForceTorqueSensor("ReplayForceTorqueSensor"),
    task(this, taskName),
    port(task, portName)    
{

}

OutputProxyPort< base::samples::Wrenches >& ForceTorqueSensor::getStatusPort()
{
    return port.getPort();
}   
    
}