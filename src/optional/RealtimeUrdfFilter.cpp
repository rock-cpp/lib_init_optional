#include "RealtimeUrdfFilter.hpp"

init::RealtimeUrdfFilter::RealtimeUrdfFilter(init::DistanceImageProvider& distImage, const std::string& taskName): 
    DistanceImageProvider("RealtimeUrdfFilter"),
    filterTask(this, taskName)
{
    registerDependency(distImage);
}

OutputProxyPort< base::samples::DistanceImage >& init::RealtimeUrdfFilter::getDistanceImagePort()
{
    return filterTask.getConcreteProxy()->output_depth;
}
