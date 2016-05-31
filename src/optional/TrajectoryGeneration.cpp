#include "TrajectoryGeneration.hpp"
#include <trajectory_generation/proxies/Task.hpp>

namespace init
{
    
TrajectoryGeneration::TrajectoryGeneration(JointDriver& jd, const std::string& trajCtrlTaskName)
    : Base("TrajectoryGeneration")
    , jointDriver(jd)
    , trajCtrlTask(this, trajCtrlTaskName)
{
    registerDependency(jointDriver);
}

bool TrajectoryGeneration::connect()
{
    jointDriver.getStatusPort().connectTo(trajCtrlTask.getConcreteProxy()->joint_state);
    trajCtrlTask.getConcreteProxy()->cmd.connectTo(jointDriver.getCommandPort());
    
    return Base::connect();
}

InputProxyPort< base::samples::Joints >& TrajectoryGeneration::getPositionTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->position_target;
}

InputProxyPort< base::JointsTrajectory >& TrajectoryGeneration::getTrajectoryTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->trajectory_target;
}

OutputProxyPort< base::samples::Joints >& TrajectoryGeneration::getJointStatusPort()
{
    return jointDriver.getStatusPort();
}

}