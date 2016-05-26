#pragma once

#include "../Base.hpp"
#include "../JointDriver.hpp"
#include <trajectory_generation/ConstrainedJointsTrajectory.hpp>
#include <trajectory_generation/trajectory_generationTypes.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>

namespace trajectory_generation {
    namespace proxies {
        class RMLVelocityTask;
    }
}

namespace init
{

class TrajectoryGenerationVelocity : public Base {
protected:
    JointDriver &jointDriver;
    
public:
    DependentTask< trajectory_generation::proxies::RMLVelocityTask > trajCtrlTask;
    TrajectoryControl(JointDriver &jd, const std::string &trajCtrlTaskName);
    
    virtual InputProxyPort< base::commands::Joints >& getVelocityTargetPort();
    
    virtual bool connect();
};

}