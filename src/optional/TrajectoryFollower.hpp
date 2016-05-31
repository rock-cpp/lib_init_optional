#pragma once

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
    PositionProvider &posProv;
    MotionControl2D &motionController;
    
public:
    DependentTask< trajectory_follower::proxies::Task > trajectoryFollowerTask;
    TrajectoryFollower(PositionProvider &posProv,  MotionControl2D &motionController, const std::string &trajectoryFollowerTaskName);
    virtual bool connect();
    virtual OutputProxyPort<base::commands::Motion2D> &getCommandOut();
};



}