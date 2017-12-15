#pragma once

#include <lib_init/TrajectoryFollower.hpp>
#include <trajectory_follower/TrajectoryFollowerTypes.hpp>
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class TrajectoryFollower : public init::Base
{
    ReplayTask task;
    ReplayPort<trajectory_follower::FollowerData> followerDataPort;
public:
    TrajectoryFollower(const std::string& taskName, const std::string& followerDataPortName);
    
    OutputProxyPort<trajectory_follower::FollowerData>& getFollowerData();
};

}
