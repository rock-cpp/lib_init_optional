#include "SimJointDriver.hpp"
#include <mars/proxies/Joints.hpp>
#include <orocos_cpp/Spawner.hpp>

namespace init
{

SimJointDriver::SimJointDriver(Simulator& sim, const std::string &marsJointTaskName) : JointDriver("SimJointDriver")
    , jointTask(DependentTask<mars::proxies::Joints>::getInstance(this, marsJointTaskName))
{
    jointTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}


InputProxyPort< base::commands::Joints >& SimJointDriver::getCommandPort()
{
    return jointTask.getConcreteProxy()->command;
}

OutputProxyPort< base::samples::Joints >& SimJointDriver::getStatusPort()
{
    return jointTask.getConcreteProxy()->joints_status;
}

void SimJointDriver::setJoints(const base::samples::Joints &jointsStatus)
{
	jointTask.getConcreteProxy()->setJoints(jointsStatus);
}
}
