#pragma once

#include <lib_init/PositionProvider.hpp>
#include <lib_init/MLSProvider.hpp>
#include <ugv_nav4d/proxies/PoseWatchdog.hpp>
#include <lib_init/MLTraversabilityMapProvider.hpp>
#include <trajectory_follower/SubTrajectory.hpp>

namespace init
{ 

class PoseWatchdog : public Base {
protected:
    PositionProvider &posProv; //provides the pose that should be watched
    MLTraversabilityMapProvider& mlMapProv;
//     MotionControl2D &motionController;
    
public:
    DependentTask< ugv_nav4d::proxies::PoseWatchdog > watchdogTask;
    
    PoseWatchdog(PositionProvider &poseProvider, MLTraversabilityMapProvider& mlMapProvider, const std::string &taskname);
    virtual bool connect();
    virtual InputProxyPort<std::vector<trajectory_follower::SubTrajectory>> &getTrajectoryIn();
    virtual OutputProxyPort<base::commands::Motion2D> &getOverrideMotionCommand();
};



} 