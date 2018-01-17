#pragma once

#include <lib_init/PositionProvider.hpp>
#include "MLSProvider.hpp"
#include <ugv_nav4d/proxies/PoseWatchdogForward.hpp>
#include <trajectory_follower/SubTrajectory.hpp>
#include <lib_init/MotionControl2DProvider.hpp>
#include <base/commands/Motion2D.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{ 

class PoseWatchdog : public MotionControl2DProvider {
protected:
    PositionProvider &posProv; //provides the pose that should be watched
    MLSProvider& mapProvider;
    
public:
    DependentTask< ugv_nav4d::proxies::PoseWatchdog > watchdogTask;
    
    PoseWatchdog(PositionProvider &poseProvider, MLSProvider& mapProvider, const std::string &taskname);

    virtual bool connect();
    virtual InputProxyPort<std::vector<trajectory_follower::SubTrajectory>> &getTrajectoryIn();
    virtual OutputProxyPort<base::commands::Motion2D> &getCommand2DPort() override;
};



} 