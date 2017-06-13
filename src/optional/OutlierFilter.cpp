#include "OutlierFilter.hpp"

init::OutlierFilter::OutlierFilter(const std::string& taskName, DepthMapProvider &input): 
    DepthMapProvider(taskName), 
    input(input),
    filterTask(this, taskName)
{

}

bool init::OutlierFilter::connect()
{
    input.getDepthMapPort().connectTo(filterTask.getConcreteProxy()->depth_map, RTT::ConnPolicy::buffer(20));
    
    return init::Base::connect();
}

OutputProxyPort< base::samples::DepthMap >& init::OutlierFilter::getDepthMapPort()
{
    return filterTask.getConcreteProxy()->filtered_depth_map;
}
