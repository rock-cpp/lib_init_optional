#pragma once

#include <lib_init/DistanceImageProvider.hpp>
#include "RobotFrames.hpp"
#include <realtime_urdf_filter/proxies/RealtimeURDFFilterTaskForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init {

class RealtimeUrdfFilter : public init::DistanceImageProvider
{
    init::RobotFrames &frame;
    init::DistanceImageProvider *distImageLeft;
    init::DistanceImageProvider *distImageRight;
public:
    RealtimeUrdfFilter(const std::string &taskName, init::DistanceImageProvider &distImage, init::RobotFrames &frames);
    RealtimeUrdfFilter(const std::string &taskName, init::DistanceImageProvider &distImageLeft, init::DistanceImageProvider &distImageRight, init::RobotFrames &frames);

    virtual bool connect();
    virtual bool start();
    
    virtual OutputProxyPort< base::samples::DistanceImage >& getDistanceImagePort();
    
    DependentTask<realtime_urdf_filter::proxies::RealtimeURDFFilterTask> filterTask;
};
    
}


