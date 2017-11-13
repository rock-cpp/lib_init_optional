#include "IMUDriver.hpp"

namespace log_replay
{
IMUDriver::IMUDriver(const std::string& taskName, const std::string& sensorPortName, const std::string& orentationPortName):
    init::Base("ReplayIMUDriver"),
    init::IMUDriver("ReplayIMUDriver"),
    task(this, taskName),
    sensorPort(task, sensorPortName),
    orientationPort(task, orentationPortName)
{

}

OutputProxyPort< base::samples::RigidBodyState > IMUDriver::getOrientationSamples()
{
    return orientationPort.getPort();
}

OutputProxyPort< base::samples::IMUSensors > IMUDriver::getSensorSamples()
{
    return sensorPort.getPort();
}

bool IMUDriver::estimate_bias(uint16_t seconds)
{
    return false;
}

}