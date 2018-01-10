#pragma once

#include <lib_init/IMUDriver.hpp>
#include <lib_init/PositionProvider.hpp>
#include "Simulator.hpp"

#include <mars/proxies/IMUForward.hpp>

namespace init 
{

class SimIMUDriver : public IMUDriver, public PositionProvider
{
public:
    SimIMUDriver(const std::string& imuTaskName, init::Simulator& sim);
    virtual OutputProxyPort< base::samples::RigidBodyState > getOrientationSamples();
    virtual OutputProxyPort< base::samples::IMUSensors > getSensorSamples();
    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
    
    bool estimate_bias(uint16_t seconds) {return true;} // Does nothing for simulated IMU

    DependentTask<mars::proxies::IMU> imuTask;
};

}


