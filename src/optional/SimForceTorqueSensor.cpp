#include "SimForceTorqueSensor.hpp"
#include <mars/proxies/ForceTorque6DOF.hpp>

init::SimForceTorqueSensor::SimForceTorqueSensor(init::Simulator& sim, const std::string& taskName): 
    ForceTorqueSensor("SimForceTorqueSensor"), 
    sim(sim),
    sensorTask(DependentTask<mars::proxies::ForceTorque6DOF>::getInstance(this, taskName))
{
    registerDependency(sim);
    sensorTask.setDeployment(sim.simulator.getDeployment());
}

OutputProxyPort< base::samples::Wrenches >& init::SimForceTorqueSensor::getStatusPort()
{
    return sensorTask.getConcreteProxy()->wrenches;
}
