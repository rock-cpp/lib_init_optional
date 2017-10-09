#include "PoseWatchdog.hpp"

namespace init
{

    
PoseWatchdog::PoseWatchdog(PositionProvider &posProv, MLTraversabilityMapProvider& mlMapProvider, const std::string &taskname)
    : Base("PoseWatchdog")
    , posProv(posProv)
    , mlMapProv(mlMapProvider)
//     , motionController(motionController)
    , watchdogTask(this, taskname)
{
    registerDependency(posProv);
    registerDependency(mlMapProvider);
//     registerDependency(motionController);
}

bool PoseWatchdog::connect()
{
    posProv.getPositionSamples().connectTo(watchdogTask.getConcreteProxy()->robot_pose);
    mlMapProv.getTraversabilityMapPort().connectTo(watchdogTask.getConcreteProxy()->tr_map);
//     trajectoryFollowerTask.getConcreteProxy()->motion_command.connectTo(motionController.getCommand2DPort());    
    return init::Base::connect();
}

// OutputProxyPort< base::commands::Motion2D >& PoseWatchdog::getCommandOut()
// {
//     return trajectoryFollowerTask.getConcreteProxy()->motion_command;
// }


}