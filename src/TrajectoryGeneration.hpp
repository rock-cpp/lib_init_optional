#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/TrajectoryControl.hpp>
#include <base/JointsTrajectory.hpp>
#include <lib_init/DependentTask.hpp>
#include <trajectory_generation/proxies/TaskForward.hpp>


namespace init
{

class TrajectoryGeneration : public TrajectoryControl {
protected:
    JointDriver &jointDriver;
public:
    DependentTask< trajectory_generation::proxies::Task > trajCtrlTask;
    TrajectoryGeneration(JointDriver &jd, const std::string &trajCtrlTaskName);
    
    virtual bool connect();
    
    virtual InputProxyPort< base::samples::Joints >& getPositionTargetPort();
    virtual InputProxyPort< base::JointsTrajectory >& getTrajectoryTargetPort();
    
    virtual OutputProxyPort< base::samples::Joints >& getJointStatusPort();
};

}