#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/MotionControl2D.hpp>
#include <lib_init/MotionControl2DProvider.hpp>

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
public:
    SafetyController(MotionControl2D& motionControl,
                     std::vector<MotionControl2DProvider*> dependecies,
                     const std::string& taskName);
    virtual ~SafetyController();
    virtual bool connect();
    InputProxyPort<base::commands::Motion2D> &getCommand2DPort();
    RTT::base::PortInterface* addOverridePort(const std::string& portName, int priority);
    void addDependency(Base &dependency);

    DependentTask<safety_control::proxies::Task> safetyControlTask;
};
}
