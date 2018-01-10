#pragma once

#include <lib_init/DistanceImageProvider.hpp>
#include <mars/proxies/DepthCameraForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{
class Simulator;

class SimDistanceImageDriver : public DistanceImageProvider
{
public:
    SimDistanceImageDriver(Simulator &sim, const std::string &distanceImageTaskName);

    virtual OutputProxyPort< base::samples::DistanceImage >& getDistanceImagePort();

    DependentTask<mars::proxies::DepthCamera> distanceImageTask;
};

} // namespace init
