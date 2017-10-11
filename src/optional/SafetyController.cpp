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
    std::cout << "CONNECTING SAFETY OUTPUT TO MOTIONCONTROL INPUT"<<std::endl;
    safetyControlTask.getConcreteProxy()->motion_command.connectTo(motionControl.getCommand2DPort());
    return init::Base::connect();
}

InputProxyPort< base::commands::Motion2D >& SafetyController::getCommand2DPort()
{
    return safetyControlTask.getConcreteProxy()->motion_command_in;
}

InputProxyPort< base::commands::Motion2D >& SafetyController::getOverrideCommandPort()
{
    return safetyControlTask.getConcreteProxy()->motion_command_safey;
}

SafetyController::~SafetyController()
{

}



}