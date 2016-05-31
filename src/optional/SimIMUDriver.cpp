#include "SimIMUDriver.hpp"

init::SimIMUDriver::SimIMUDriver(const std::string &imuTaskName, init::Simulator& sim) : IMUDriver("SimIMUDriver"), imuTask(this, imuTaskName)
{
    imuTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

OutputProxyPort< base::samples::RigidBodyState > init::SimIMUDriver::getOrientationSamples()
{
    return imuTask.getConcreteProxy()->orientation_samples;
}

OutputProxyPort< base::samples::IMUSensors > init::SimIMUDriver::getSensorSamples()
{
    return imuTask.getConcreteProxy()->calibrated_sensors;
}
