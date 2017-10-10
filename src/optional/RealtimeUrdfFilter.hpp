#pragma once

#include <lib_init/DistanceImageProvider.hpp>
#include <realtime_urdf_filter/proxies/RealtimeURDFFilterTask.hpp>

namespace init {

class RealtimeUrdfFilter : public init::DistanceImageProvider
{
public:
    RealtimeUrdfFilter(init::DistanceImageProvider &distImage, const std::string &taskName);

    virtual OutputProxyPort< base::samples::DistanceImage >& getDistanceImagePort();
    
    DependentTask<realtime_urdf_filter::proxies::RealtimeURDFFilterTask> filterTask;
};
    
}


