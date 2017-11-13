#pragma once

#include "GenericRawToMotion2D.hpp"
#include <controldev/proxies/JoystickTaskForward.hpp>
#include <base/commands/Motion2D.hpp>
#include <lib_init/MotionControl2D.hpp>
#include <lib_init/MotionControl2DProvider.hpp>
#include <lib_init/DependentTask.hpp>

namespace init {
    
class Joypad : public MotionControl2DProvider
{
    GenericRawToMotion2D &genericRawToMotion2DConverter;
    std::shared_ptr<MotionControl2D> control;
public:
    Joypad(const std::string& taskName, GenericRawToMotion2D &genericRawToMotion2DConverter);
    virtual ~Joypad() {};
    virtual bool connect();

    virtual OutputProxyPort<base::commands::Motion2D> &getCommand2DPort();
    
    void setMotionControl(const std::shared_ptr<MotionControl2D> &control);
    
    DependentTask<controldev::proxies::JoystickTask> joypad;
};

}