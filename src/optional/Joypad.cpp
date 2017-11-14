#include "Joypad.hpp"
#include <controldev/proxies/JoystickTask.hpp>
#include <controldev/proxies/GenericRawToMotion2D.hpp>

namespace init 
{
    
Joypad::Joypad(const std::string& taskName, GenericRawToMotion2D &genericRawToMotion2DConverter)
    : Base(taskName),
      MotionControl2DProvider(taskName),
      genericRawToMotion2DConverter(genericRawToMotion2DConverter),
      joypad(DependentTask<controldev::proxies::JoystickTask>::getInstance(this, taskName))
{
	registerDependency(genericRawToMotion2DConverter);
}

bool Joypad::connect()
{
    joypad.getConcreteProxy()->raw_command.connectTo(genericRawToMotion2DConverter.converter.getConcreteProxy()->raw_command);
    
    if(control)
    {
        genericRawToMotion2DConverter.converter.getConcreteProxy()->motion_command.connectTo(control->getCommand2DPort());
    }
    
    return init::Base::connect();
}

OutputProxyPort<base::commands::Motion2D>& Joypad::getCommand2DPort()
{
    return genericRawToMotion2DConverter.converter.getConcreteProxy()->motion_command;
}
    
void Joypad::setMotionControl(const std::shared_ptr<MotionControl2D> &control)
{
    this->control = control;
    registerDependency(*control.get());
}

}