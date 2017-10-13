#pragma once

#include "TrajectoryFollower.hpp"
#include "SafetyController.hpp"
#include "PoseWatchdog.hpp"

namespace init
{

class TrajectoryFollowerWithSafeGuard : public TrajectoryFollower {
protected:
    SafetyController &safetyController;
    PoseWatchdog &poseWatchdog;
    
public:
    TrajectoryFollowerWithSafeGuard(PositionProvider &posProv, SafetyController &safetyController, PoseWatchdog &poseWatchdog,
                                    const std::string &taskName);
    virtual bool connect();
    
    virtual ~TrajectoryFollowerWithSafeGuard(){}
};


 
}