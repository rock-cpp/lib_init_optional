#include "PoseWatchdog.hpp"
#include <ugv_nav4d/proxies/PoseWatchdog.hpp>
#include <iostream>

namespace init
{

    
PoseWatchdog::PoseWatchdog(PositionProvider &posProv, MLSProvider& mapProvider, const std::string &taskname)
    : Base("PoseWatchdog"), MotionControl2DProvider("PoseWatchdog")
    , posProv(posProv)
    , mapProvider(mapProvider)
    , watchdogTask(DependentTask< ugv_nav4d::proxies::PoseWatchdog >::getInstance(this, taskname))
{
    registerDependency(posProv);
    registerDependency(mapProvider);
}

PoseWatchdog::PoseWatchdog(Simulator &provider, const std::string &taskname)
    : Base("PoseWatchdog"), MotionControl2DProvider("PoseWatchdog")
    , posProv(provider)
    , mapProvider(provider)
    , watchdogTask(DependentTask< ugv_nav4d::proxies::PoseWatchdog >::getInstance(this, taskname))
{
    registerDependency(provider);
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


OutputProxyPort<base::commands::Motion2D>& PoseWatchdog::getCommand2DPort()
{
    return watchdogTask.getConcreteProxy()->motion_command_override;
}


}