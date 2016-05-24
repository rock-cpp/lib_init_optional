#pragma once

#include <lib_init/Base.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include "Simulator.hpp"
#include <base/samples/Pointcloud.hpp>
#include <mars/proxies/RotatingLaserRangeFinder.hpp>

namespace init
{

class SimVelodyneDriver : public Base {
protected:
    OutputProxyPort< base::samples::Pointcloud > *simulatedPointcloudPort;

public:
    
    SimVelodyneDriver(Simulator &sim, const std::string &velodyneTaskName);
    virtual ~SimVelodyneDriver() {};
    virtual void initProxies();
    OutputProxyPort< base::samples::Pointcloud >& getSimulatedPointcloudPort();

    DependentTask<mars::proxies::RotatingLaserRangeFinder> velodyneTask;
};

}