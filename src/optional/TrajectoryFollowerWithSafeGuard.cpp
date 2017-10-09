#include "TrajectoryFollowerWithSafeGuard.hpp"

namespace init
{

TrajectoryFollowerWithSafeGuard::TrajectoryFollowerWithSafeGuard(PositionProvider& posProv,
                                                                 MotionControl2D& motionController,
                                                                 SafetyController& safetyController,
                                                                 PoseWatchdog &poseWatchdog,
                                                                 const std::string& taskName) :
    TrajectoryFollower(posProv, motionController, taskName),
    safetyController(safetyController), poseWatchdog(poseWatchdog)
{
    registerDependency(safetyController);
    registerDependency(poseWatchdog);
}
  
    
bool TrajectoryFollowerWithSafeGuard::connect()
{
    trajectoryFollowerTask.getConcreteProxy()->current_trajectory.connectTo(poseWatchdog.getTrajectoryIn());
    //TODO posewatchdog output and safetyController connecten, wenn es den gibt
    return init::TrajectoryFollower::connect();
}

    
}