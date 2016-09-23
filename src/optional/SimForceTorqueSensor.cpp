#include "SimForceTorqueSensor.hpp"

init::SimForceTorqueSensor::SimForceTorqueSensor(init::Simulator& sim, const std::string& taskName): 
    ForceTorqueSensor("SimForceTorqueSensor"), 
    sim(sim),
    sensorTask(this, taskName)
{
    registerDependency(sim);
    sensorTask.setDeployment(sim.simulator.getDeployment());
}

OutputProxyPort< base::samples::Wrenches >& init::SimForceTorqueSensor::getStatusPort()
{
    return sensorTask.getConcreteProxy()->wrenches;
}
