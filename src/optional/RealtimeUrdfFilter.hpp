#pragma once

#include <lib_init/DistanceImageProvider.hpp>
#include <lib_init/RobotFrames.hpp>
#include <realtime_urdf_filter/proxies/RealtimeURDFFilterTask.hpp>

namespace init {

class RealtimeUrdfFilter : public init::DistanceImageProvider
{
    init::RobotFrames &frame;
    init::DistanceImageProvider &distImage;
public:
    RealtimeUrdfFilter(const std::string &taskName, init::DistanceImageProvider &distImage, init::RobotFrames &frames);

    virtual bool connect();
    virtual bool start();
    
    virtual OutputProxyPort< base::samples::DistanceImage >& getDistanceImagePort();
    
    DependentTask<realtime_urdf_filter::proxies::RealtimeURDFFilterTask> filterTask;
};
    
}


