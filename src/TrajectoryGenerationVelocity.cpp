#include "TrajectoryGenerationVelocity.hpp"
#include <trajectory_generation/proxies/RMLVelocityTask.hpp>

namespace init
{
    
TrajectoryGenerationVelocity::TrajectoryGenerationVelocity(JointDriver& jd, const std::string& trajCtrlTaskName)
    : TrajectoryControl("TrajectoryGenerationVelocity")
    , jointDriver(jd)
    , trajCtrlTask(DependentTask< trajectory_generation::proxies::RMLVelocityTask >::getInstance(this, trajCtrlTaskName))
{
    registerDependency(jointDriver);
}

bool TrajectoryGenerationVelocity::connect()
{
    jointDriver.getStatusPort().connectTo(trajCtrlTask.getConcreteProxy()->joint_state);
    trajCtrlTask.getConcreteProxy()->command.connectTo(jointDriver.getCommandPort());
    
    return Base::connect();
}

InputProxyPort< base::commands::Joints >& TrajectoryGenerationVelocity::getVelocityTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->velocity_target;
}

InputProxyPort< trajectory_generation::ConstrainedJointsCmd >& TrajectoryGenerationVelocity::getConstrainedVelocityTargetPort()
{
    return trajCtrlTask.getConcreteProxy()->constrained_velocity_target;
}

OutputProxyPort< base::samples::Joints >& TrajectoryGenerationVelocity::getJointStatusPort()
{
    return jointDriver.getStatusPort();
}

}