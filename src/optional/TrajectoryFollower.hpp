#pragma once

#include "VelodyneSlam.hpp"
#include <trajectory_follower/Motion2D.hpp>
#include <base/Trajectory.hpp>

namespace trajectory_follower {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class TrajectoryFollower : public Base {
protected:
    
public:
    DependentTask< trajectory_follower::proxies::Task > trajectoryFollowerTask;
    TrajectoryFollower(const std::string &trajectoryFollowerTaskName);
    virtual bool connect();
    OutputProxyPort< trajectory_follower::Motion2D >& getMotionCmdPort();
    InputProxyPort< base::samples::RigidBodyState >& getRobotPosePort();
    InputProxyPort< std::vector< base::Trajectory > >& getTrajectoryPort();
};



}