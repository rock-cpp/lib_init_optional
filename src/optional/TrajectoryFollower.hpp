#pragma once

#include "VelodyneSlam.hpp"
#include <trajectory_follower/Motion2D.hpp>
#include <base/Trajectory.hpp>
#include <lib_init/PositionProvider.hpp>
#include <lib_init/MotionControl2D.hpp>

namespace trajectory_follower {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class TrajectoryFollower : public Base {
protected:
    MotionControl2D &motionControl2d;
    PositionProvider &posProv;
public:
    DependentTask< trajectory_follower::proxies::Task > trajectoryFollowerTask;
    TrajectoryFollower(MotionControl2D &ctrl, PositionProvider &posProv, const std::string &trajectoryFollowerTaskName);
    virtual bool connect();
};



}