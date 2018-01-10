#pragma once

#include <lib_init/ForceTorqueSensor.hpp>
#include "Simulator.hpp"
#include <mars/proxies/ForceTorque6DOFForward.hpp>
namespace init {

class SimForceTorqueSensor : public ForceTorqueSensor
{
    Simulator &sim;
public:
    SimForceTorqueSensor(Simulator &sim, const std::string& taskName);
    virtual OutputProxyPort< base::samples::Wrenches >& getStatusPort();

    DependentTask<mars::proxies::ForceTorque6DOF> sensorTask;
};

}
