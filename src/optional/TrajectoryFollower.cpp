#include "TrajectoryFollower.hpp"

#include <trajectory_follower/proxies/Task.hpp>

namespace init
{

    
TrajectoryFollower::TrajectoryFollower(MotionControl2D &ctrl, PositionProvider &posProv, const std::string &trajectoryFollowerTaskName)
    : Base("TrajectoryFollower")
    , motionControl2d(ctrl)
    , posProv(posProv)
    , trajectoryFollowerTask(this, trajectoryFollowerTaskName, "trajectory_follower::Task")
{
}

bool TrajectoryFollower::connect()
{
    trajectoryFollowerTask.getConcreteProxy()->motion_command.connectTo(motionControl2d.getCommand2DPort());
    posProv.getPositionSamples().connectTo(trajectoryFollowerTask.getConcreteProxy()->robot_pose);
    
    return init::Base::connect();
}


}