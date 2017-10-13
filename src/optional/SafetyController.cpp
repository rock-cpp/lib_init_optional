#include "SafetyController.hpp"
#include <safety_control/proxies/Task.hpp>

namespace init
{

    
SafetyController::SafetyController(MotionControl2D& motionControl, const std::string& taskName)
  : SafetyController(motionControl, nullptr, taskName)
{
}

SafetyController::SafetyController(MotionControl2D& motionControl, MotionControl2DProvider *joypad, const std::string& taskName)
    : Base("SafetyController"),
      MotionControl2D("SafetyController"),
      motionControl(motionControl),
      joyPtr(joypad),
      safetyControlTask(this, taskName)
{
    registerDependency(motionControl);
    if(joyPtr)
      registerDependency(*joyPtr);
      
}

 
  
bool SafetyController::connect()
{
    std::cout << "CONNECTING SAFETY OUTPUT TO MOTIONCONTROL INPUT"<<std::endl;
    safetyControlTask.getConcreteProxy()->motion_command.connectTo(motionControl.getCommand2DPort());
    if(joyPtr)
      joyPtr->getCommand2DPort().connectTo(safetyControlTask.getConcreteProxy()->motion_command_safety);
    safetyControlTask.getConcreteProxy()->motion_command.connectTo(motionControl.getCommand2DPort());
    return init::Base::connect();
}

InputProxyPort< base::commands::Motion2D >& SafetyController::getCommand2DPort()
{
    return safetyControlTask.getConcreteProxy()->motion_command_in;
}


InputProxyPort< base::commands::Motion2D >& SafetyController::getPoseWatchdogOverrideCommandPort()
{
    return safetyControlTask.getConcreteProxy()->posewatchdog_in;
}

InputProxyPort< base::commands::Motion2D >& SafetyController::getDofcOverrideCommandPort()
{
    return safetyControlTask.getConcreteProxy()->dofc_in;
}

InputProxyPort< base::commands::Motion2D >& SafetyController::getSafetyOverrideCommandPort()
{
    return safetyControlTask.getConcreteProxy()->motion_command_safety;
}

SafetyController::~SafetyController()
{

}



}
