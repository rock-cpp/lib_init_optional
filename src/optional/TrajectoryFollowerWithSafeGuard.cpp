#include "TrajectoryFollowerWithSafeGuard.hpp"
#include <safety_control/proxies/Task.hpp>

namespace init
{

TrajectoryFollowerWithSafeGuard::TrajectoryFollowerWithSafeGuard(PositionProvider& posProv,
                                                                 SafetyController& safetyController,
                                                                 PoseWatchdog &poseWatchdog,
                                                                 const std::string& taskName) :
    TrajectoryFollower(posProv, safetyController, taskName), poseWatchdog(poseWatchdog)
{
    registerDependency(poseWatchdog);
}
  
    
bool TrajectoryFollowerWithSafeGuard::connect()
{
    trajectoryFollowerTask.getConcreteProxy()->current_trajectory.connectTo(poseWatchdog.getTrajectoryIn());
    posProv.getPositionSamples().connectTo(trajectoryFollowerTask.getConcreteProxy()->robot_pose);

    return TrajectoryFollower::connect();
}

    
}