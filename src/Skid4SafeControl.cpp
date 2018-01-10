#include "Skid4SafeControl.hpp"
#include <skid4_control/proxies/SafeController.hpp>

namespace init 
{

Skid4SafeControl::Skid4SafeControl(const std::string &controlTaskName, JointDriver &dispatcher) : 
    Base("Skid4SafeControl"),
    MotionControl2D("Skid4SafeControl"), 
    dispatcher(dispatcher),
    motionTask(DependentTask<skid4_control::proxies::SafeController>::getInstance(this, controlTaskName))
{
    registerDependency(dispatcher);
}

bool Skid4SafeControl::connect()
{
    motionTask.getConcreteProxy()->command.connectTo(dispatcher.getCommandPort());
    
    dispatcher.getStatusPort().connectTo(motionTask.getConcreteProxy()->status_samples, RTT::ConnPolicy::buffer(50));
    
    return init::Base::connect();
}

InputProxyPort< base::commands::Motion2D >& Skid4SafeControl::getCommand2DPort()
{
    return motionTask.getConcreteProxy()->motion_command;
}


}