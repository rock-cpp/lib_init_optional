#include "TrajectoryFollower.hpp"
#include <trajectory_follower/proxies/Task.hpp>


namespace init
{

    
TrajectoryFollower::TrajectoryFollower(PositionProvider &posProv, MotionControl2D &motionController, const std::string &trajectoryFollowerTaskName)
    : Base("TrajectoryFollower")
    , posProv(posProv)
    , motionController(motionController)
    , trajectoryFollowerTask(DependentTask< trajectory_follower::proxies::Task >::getInstance(this, trajectoryFollowerTaskName))
{
    registerDependency(posProv);
    registerDependency(motionController);
}

bool TrajectoryFollower::connect()
{
    posProv.getPositionSamples().connectTo(trajectoryFollowerTask.getConcreteProxy()->robot_pose);
    trajectoryFollowerTask.getConcreteProxy()->motion_command.connectTo(motionController.getCommand2DPort());    
    return init::Base::connect();
}

OutputProxyPort< base::commands::Motion2D >& TrajectoryFollower::getCommandOut()
{
    return trajectoryFollowerTask.getConcreteProxy()->motion_command;
}




}