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
    poseWatchdog.getOverrideMotionCommand().connectTo(safetyController.getPoseWatchdogOverrideCommandPort());
    posProv.getPositionSamples().connectTo(trajectoryFollowerTask.getConcreteProxy()->robot_pose);
    trajectoryFollowerTask.getConcreteProxy()->motion_command.connectTo(safetyController.getCommand2DPort());  

    //NOTE we do not call  TrajectoryFollower::connect() here on purpose because
    //     it connects the trajectoryFollowerTask directly to motionController, which is not what we want.
    return init::Base::connect();
}

    
}