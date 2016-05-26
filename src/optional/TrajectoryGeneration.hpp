#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/JointDriver.hpp>

namespace trajectory_generation {
    namespace proxies {
        class Task;
    }
}

namespace init
{

class TrajectoryGeneration : public Base {
protected:
    JointDriver &jointDriver;
    
public:
    DependentTask< trajectory_generation::proxies::Task > trajCtrlTask;
    TrajectoryControl(JointDriver &jd, const std::string &trajCtrlTaskName);
    virtual bool connect();
};

}