#include "Dynamixel.hpp"
#include <servo_dynamixel/proxies/Task.hpp>

init::Dynamixel::Dynamixel(const std::string& taskName) : 
    JointDriver("Dynamixel"), 
    dynamixel(DependentTask<servo_dynamixel::proxies::Task>::getInstance(this, taskName))
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
