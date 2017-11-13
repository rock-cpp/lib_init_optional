#pragma once

#include <lib_init/IMUDriver.hpp>
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class IMUDriver : public init::IMUDriver
{
    ReplayTask task;
    ReplayPort<base::samples::IMUSensors> sensorPort;
    ReplayPort<base::samples::RigidBodyState> orientationPort;
public :
    IMUDriver(const std::string& taskName, const std::string& sensorPortName, const std::string& orentationPortName);
    
    virtual OutputProxyPort< base::samples::RigidBodyState > getOrientationSamples();
    virtual OutputProxyPort< base::samples::IMUSensors > getSensorSamples();
    virtual bool estimate_bias(uint16_t seconds);
};

}

