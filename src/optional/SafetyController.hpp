#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/MotionControl2D.hpp>
#include <lib_init/MotionControl2DProvider.hpp>
#include <map>
#include <lib_init/DependentTask.hpp>

namespace safety_control {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class SafetyController : public MotionControl2D
{
protected:
    MotionControl2D &motionControl;
    std::map<int, MotionControl2DProvider*> safetyInputs;
    
    RTT::base::PortInterface* addOverridePort(const std::string& portName, int priority);
public:
    /** @param safetyInputs key value pairs of override inputs.
      *                     key=priority */
    SafetyController(MotionControl2D& motionControl,
                     std::map<int, MotionControl2DProvider*> safetyInputs, 
                     const std::string& taskName);
    virtual ~SafetyController();
    virtual bool connect();
    
    void addSafetyInput(int prio, MotionControl2DProvider* task);
    InputProxyPort<base::commands::Motion2D> &getCommand2DPort();
    DependentTask<safety_control::proxies::Task> safetyControlTask;
};
}
