#include "RealtimeUrdfFilter.hpp"

init::RealtimeUrdfFilter::RealtimeUrdfFilter(const std::string& taskName, init::DistanceImageProvider& distImage, init::RobotFrames &frame): 
    DistanceImageProvider("RealtimeUrdfFilter"),
    frame(frame),
    distImage(distImage),
    filterTask(this, taskName)
{
    registerDependency(distImage);
    registerDependency(frame);
}

bool init::RealtimeUrdfFilter::connect()
{
    distImage.getDistanceImagePort().connectTo(filterTask.getConcreteProxy()->input_depth, RTT::ConnPolicy::buffer(10));
    return init::Base::connect();
}

bool init::RealtimeUrdfFilter::start()
{
    //this is hacky and ugly, but the task does not honor any convetions, so....
    frame.robotFrames.getConcreteProxy()->synchronize();
    
    RTT::DataFlowInterface *fi = frame.robotFrames.getConcreteProxy()->ports();
    
    for(RTT::base::PortInterface *pi : fi->getPorts())
    {
        std::string tn = pi->getTypeInfo()->getTypeName();
        if(tn == "/base/samples/RigidBodyState")
        {
            pi->connectTo(filterTask.getConcreteProxy()->input_tf.getPortInterface(), RTT::ConnPolicy::buffer(100));
        }
    }
    
    return init::Base::start();
}


OutputProxyPort< base::samples::DistanceImage >& init::RealtimeUrdfFilter::getDistanceImagePort()
{
    return filterTask.getConcreteProxy()->output_depth;
}
