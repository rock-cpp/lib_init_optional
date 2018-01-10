#include "SimIMUDriver.hpp"
#include <mars/proxies/IMU.hpp>

init::SimIMUDriver::SimIMUDriver(const std::string &imuTaskName, init::Simulator& sim) : Base("SimIMUDriver"), IMUDriver("SimIMUDriver"), PositionProvider("SimIMUDriver")
    , imuTask(DependentTask<mars::proxies::IMU>::getInstance(this, imuTaskName))
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

OutputProxyPort< base::samples::RigidBodyState >& init::SimIMUDriver::getPositionSamples()
{
    return imuTask.getConcreteProxy()->orientation_samples;
}
