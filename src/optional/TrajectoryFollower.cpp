#include "TrajectoryFollower.hpp"

#include <trajectory_follower/proxies/Task.hpp>

namespace init
{

TrajectoryFollower::TrajectoryFollower(VelodyneSlamDriver &vsd, const std::string &trajectoryFollowerTaskName)
    : Base("TrajectoryFollower"),
      trajectoryFollowerTask(this, trajectoryFollowerTaskName, "trajectory_follower::Task"),
      velodyneSlam(vsd)
{
    registerDependency(velodyneSlam);
}

bool TrajectoryFollower::connect()
{
    velodyneSlam.getPoseSamplesPort().connectTo(trajectoryFollowerTask.getConcreteProxy()->robot_pose);
    return init::Base::connect();
}


OutputProxyPort< trajectory_follower::Motion2D >& TrajectoryFollower::getMotionCmdPort()
{
    return trajectoryFollowerTask.getConcreteProxy()->motion_command;
}

}
