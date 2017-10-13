#include "Skid4MotionControl.hpp"

namespace init 
{

Skid4MotionControl::Skid4MotionControl(const std::string &controlTaskName, JointDriver &dispatcher) : 
    Base("MotionControl"),
    MotionControl2D("MotionControl"), 
    dispatcher(dispatcher),
    motionTask(new DependentTask<skid4_control::proxies::SimpleController>(this, controlTaskName))
{
    registerDependency(dispatcher);
}

bool Skid4MotionControl::connect()
{
    motionTask->getConcreteProxy()->command.connectTo(dispatcher.getCommandPort());
    
    dispatcher.getStatusPort().connectTo(motionTask->getConcreteProxy()->status_samples, RTT::ConnPolicy::buffer(50));
    
    return init::Base::connect();
}

InputProxyPort< base::commands::Motion2D >& Skid4MotionControl::getCommand2DPort()
{
    return motionTask->getConcreteProxy()->motion_command;
}


}