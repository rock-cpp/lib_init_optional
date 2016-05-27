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
    TrajectoryGenerationVelocity(JointDriver &jd, const std::string &trajCtrlTaskName);
    
    virtual InputProxyPort< base::samples::Joints >& getVelocityTargetPort();
    virtual InputProxyPort< trajectory_generation::ConstrainedJointsCmd >& getConstrainedVelocityTargetPort();
    
    virtual OutputProxyPort< base::samples::Joints >& getJointStatusPort();
    
    virtual bool connect();
};

}