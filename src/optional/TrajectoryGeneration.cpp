#include "TrajectoryGeneration.hpp"
#include <trajectory_generation/proxies/Task.hpp>

namespace init
{
    
TrajectoryGeneration::TrajectoryGeneration(JointDriver& jd, const std::string& trajCtrlTaskName)
    : Base("TrajectoryControl")
    , jointDriver(jd)
    , trajCtrlTask(this, trajCtrlTaskName, "trajectory_generation::Task")
{
    registerDependency(jointDriver);
}

bool TrajectoryGeneration::connect()
{
    jointDriver.getStatusPort().connectTo(trajCtrlTask.getConcreteProxy()->joint_state);
    trajCtrlTask.getConcreteProxy()->cmd.connectTo(jointDriver.getCommandPort());
    
    return Base::connect();
}

}