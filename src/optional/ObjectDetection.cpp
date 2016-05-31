#include "ObjectDetection.hpp"
#include <sb_object_detection/proxies/Task.hpp>

namespace init
{
    
ObjectDetection::ObjectDetection(ColorizedPointcloud &colorPCl, const std::string &objectDetectionTaskName)
     : Base("ObjectDetection")
     , colorizedPointcloud(colorPCl)
     , objectDetectionTask(this, objectDetectionTaskName)
{
     registerDependency(colorizedPointcloud);
}
     
bool ObjectDetection::connect()
{
     colorizedPointcloud.getColorizedPointcloud().connectTo(objectDetectionTask.getConcreteProxy()->colored_points, RTT::ConnPolicy::buffer(5));
     return Base::connect();
}
    
}