#pragma once

#include <lib_init/VelodyneSlamDriver.hpp>
#include <trajectory_follower/Motion2D.hpp>

namespace trajectory_follower {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class TrajectoryFollower : public Base {
protected:
    VelodyneSlamDriver &velodyneSlam;
    
public:
    DependentTask< trajectory_follower::proxies::Task > trajectoryFollowerTask;
    TrajectoryFollower(VelodyneSlamDriver &vsd, const std::string &trajectoryFollowerTaskName);
    virtual bool connect();
    OutputProxyPort< trajectory_follower::Motion2D >& getMotionCmdPort();
};

}