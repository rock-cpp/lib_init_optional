#include "SafetyController.hpp"
#include <safety_control/proxies/Task.hpp>


namespace init
{

SafetyController::SafetyController(MotionControl2D& motionControl, const std::string& taskName)
    : Base("SafetyController"),
      MotionControl2D("SafetyController"),
      motionControl(motionControl),
      safetyControlTask(this, taskName)
{
    registerDependency(motionControl);
}

 
  
bool SafetyController::connect()
{
    safetyControlTask.getConcreteProxy()->motion_command.connectTo(motionControl.getCommand2DPort());
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
