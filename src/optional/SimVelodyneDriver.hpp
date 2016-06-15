#pragma once

#include <lib_init/PointCloudProvider.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include "Simulator.hpp"
#include <base/samples/Pointcloud.hpp>
#include <mars/proxies/RotatingLaserRangeFinder.hpp>

namespace init
{

class SimVelodyneDriver : public PointCloudProvider {
protected:
    OutputProxyPort< base::samples::Pointcloud > *simulatedPointcloudPort;

public:
    
    SimVelodyneDriver(Simulator &sim, const std::string &velodyneTaskName);

    virtual ~SimVelodyneDriver();
    virtual void initProxies();

    virtual OutputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
    
    DependentTask<mars::proxies::RotatingLaserRangeFinder> velodyneTask;
};

}