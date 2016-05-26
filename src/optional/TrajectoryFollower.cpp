#include "TrajectoryFollower.hpp"

#include <trajectory_follower/proxies/Task.hpp>

namespace init
{

TrajectoryFollower::TrajectoryFollower(const std::string &trajectoryFollowerTaskName)
    : Base("TrajectoryFollower"),
      trajectoryFollowerTask(this, trajectoryFollowerTaskName, "trajectory_follower::Task")
{
}

bool TrajectoryFollower::connect()
{
    return init::Base::connect();
}

OutputProxyPort< trajectory_follower::Motion2D >& TrajectoryFollower::getMotionCmdPort()
{
    return trajectoryFollowerTask.getConcreteProxy()->motion_command;
}

InputProxyPort< base::samples::RigidBodyState >& TrajectoryFollower::getRobotPosePort()
{
    return trajectoryFollowerTask.getConcreteProxy()->robot_pose;
}

InputProxyPort< std::vector< base::Trajectory > >& TrajectoryFollower::getTrajectoryPort()
{
    return trajectoryFollowerTask.getConcreteProxy()->trajectory;
}

}