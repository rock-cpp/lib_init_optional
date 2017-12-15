#include "SafetyController.hpp"
#include <safety_control/proxies/Task.hpp>


namespace init
{

SafetyController::SafetyController(MotionControl2D& motionControl, std::map<int, MotionControl2DProvider*> safetyInputs,
                                   const std::string& taskName)
    : Base("SafetyController"),
      MotionControl2D("SafetyController"),
      motionControl(motionControl),
      safetyInputs(safetyInputs),
      safetyControlTask(DependentTask<safety_control::proxies::Task>::getInstance(this, taskName))
{
    registerDependency(motionControl);
    
    for(auto pair : safetyInputs)
        registerDependency(*pair.second);
}

void SafetyController::addSafetyInput(int prio, MotionControl2DProvider* task)
{
    safetyInputs.insert(std::make_pair(prio, task));
//    registerDependency(*task);
}


  
bool SafetyController::connect()
{
    safetyControlTask.getConcreteProxy()->motion_command.connectTo(motionControl.getCommand2DPort());
    
    for(auto pair : safetyInputs)
    {
        const int prio = pair.first;
        MotionControl2DProvider* input = pair.second;
        const std::string name = input->getName() + "_override_input";
        
        RTT::base::PortInterface* inputPort = addOverridePort(name, prio);
        input->getCommand2DPort().getPortInterface()->connectTo(inputPort);
    }
    
    return init::Base::connect();
}

InputProxyPort< base::commands::Motion2D >& SafetyController::getCommand2DPort()
{
    return safetyControlTask.getConcreteProxy()->motion_command_in;
}

RTT::base::PortInterface* SafetyController::addOverridePort(const std::string& portName, int priority)
{
    if(safetyControlTask.getConcreteProxy()->addSafetyPort(portName, priority) != 0)
    {
        throw std::runtime_error("Failed to add port to safety_control");
    }
    safetyControlTask.getConcreteProxy()->synchronize();
    RTT::base::PortInterface *port = safetyControlTask.getConcreteProxy()->getPort(portName);
    if(port == nullptr)
        throw std::runtime_error("Failed to add port to safety_control. [nullptr] returned");
    return port;
}

SafetyController::~SafetyController()
{}



}
