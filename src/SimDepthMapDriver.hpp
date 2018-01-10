#pragma once

#include <lib_init/DepthMapProvider.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include "Simulator.hpp"
#include <base/samples/DepthMap.hpp>
#include <mars/proxies/RotatingLaserRangeFinderForward.hpp>

namespace init
{

class SimDepthMapDriver : public DepthMapProvider {
protected:
    OutputProxyPort< base::samples::DepthMap > *simulatedDepthMapPort;

public:

    SimDepthMapDriver(Simulator &sim, const std::string &velodyneTaskName);

    virtual ~SimDepthMapDriver();
    virtual void initProxies();

    virtual OutputProxyPort< base::samples::DepthMap >& getDepthMapPort();

    DependentTask<mars::proxies::RotatingLaserRangeFinder> velodyneTask;
};

}