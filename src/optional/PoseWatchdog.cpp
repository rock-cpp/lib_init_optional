#include "PoseWatchdog.hpp"
#include <iostream>

namespace init
{

    
PoseWatchdog::PoseWatchdog(PositionProvider &posProv, MLSProvider& mapProvider, const std::string &taskname)
    : Base("PoseWatchdog")
    , posProv(posProv)
    , mapProvider(mapProvider)
    , watchdogTask(this, taskname)
{
    registerDependency(posProv);
    registerDependency(mapProvider);
}

bool PoseWatchdog::connect()
{
    posProv.getPositionSamples().connectTo(watchdogTask.getConcreteProxy()->robot_pose);
    mapProvider.getMapPort().connectTo(watchdogTask.getConcreteProxy()->map);
    return init::Base::connect();
}

InputProxyPort<std::vector<trajectory_follower::SubTrajectory>>& PoseWatchdog::getTrajectoryIn()
{
    return watchdogTask.getConcreteProxy()->currentTrajectory;
}


OutputProxyPort< base::commands::Motion2D >& PoseWatchdog::getOverrideMotionCommand()
{
    return watchdogTask.getConcreteProxy()->motion_command_override;
}


}