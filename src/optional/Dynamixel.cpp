#include "Dynamixel.hpp"

init::Dynamixel::Dynamixel(const std::string& taskName) : JointDriver("Dynamixel"), dynamixel(this, taskName, "servo_dynamixel::Task")
{
    
}

InputProxyPort< base::commands::Joints >& init::Dynamixel::getCommandPort()
{
    return dynamixel.getConcreteProxy()->command;
}

OutputProxyPort< base::samples::Joints >& init::Dynamixel::getStatusPort()
{
    return dynamixel.getConcreteProxy()->status_samples;
}
