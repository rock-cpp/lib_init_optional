#pragma once

#include <lib_init/JointDriver.hpp>
#include <servo_dynamixel/proxies/Task.hpp>

namespace init 
{

class Dynamixel : public JointDriver
{
public:
    Dynamixel(const std::string &taskName);
    virtual InputProxyPort< base::commands::Joints >& getCommandPort();
    virtual OutputProxyPort< base::samples::Joints >& getStatusPort();
    
    DependentTask<servo_dynamixel::proxies::Task> dynamixel;
};

}
