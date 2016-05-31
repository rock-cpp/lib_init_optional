#include "SimJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>

namespace init
{

SimJointDriver::SimJointDriver(Simulator& sim, const std::string &marsJointTaskName) : JointDriver("SimJointDriver"), jointTask(this, marsJointTaskName)
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
    return jointTask.getConcreteProxy()->status_samples;
}
}
