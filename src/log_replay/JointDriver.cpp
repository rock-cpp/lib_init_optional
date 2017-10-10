#include "JointDriver.hpp"

log_replay::JointDriver::JointDriver(const std::string& taskName, const std::string& portName): 
    init::JointDriver("ReplayJointDriver"),
    task(this, taskName),
    port(task, portName)

{

}

InputProxyPort< base::commands::Joints >& log_replay::JointDriver::getCommandPort()
{
    throw std::runtime_error("Replay does not feature joint command port");
}

OutputProxyPort< base::samples::Joints >& log_replay::JointDriver::getStatusPort()
{
    return port.getPort();
}
