#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/MotionControl2D.hpp>
#include <skid4_control/proxies/SafeController.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class Skid4SafeControl : public MotionControl2D
{
    JointDriver &dispatcher;
public:
    Skid4SafeControl(const std::string &controlTaskName, JointDriver &dispatcher);
    virtual InputProxyPort< base::commands::Motion2D >& getCommand2DPort();    
    virtual bool connect();
    
    DependentTask<skid4_control::proxies::SafeController> *motionTask;
};

}

