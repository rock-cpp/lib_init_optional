#pragma once

#include <lib_init/IMUDriver.hpp>
#include "Simulator.hpp"

#include <mars/proxies/IMU.hpp>

namespace init 
{

class SimIMUDriver : public IMUDriver
{
public:
    SimIMUDriver(const std::string& imuTaskName, init::Simulator& sim);
    virtual OutputProxyPort< base::samples::RigidBodyState > getOrientationSamples();
    virtual OutputProxyPort< base::samples::IMUSensors > getSensorSamples();
    
    DependentTask<mars::proxies::IMU> imuTask;
};

}


