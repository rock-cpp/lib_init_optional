#include "DepthMapToPCLConverter.hpp"

init::DepthMapToPCLConverter::DepthMapToPCLConverter(init::DepthMapProvider& velodyne, const std::string &converterTaskName):
    PointCloudProvider("DepthMapToPCLConverter"), 
    velodyne(velodyne), 
    converter(this, converterTaskName)
{
    registerDependency(velodyne);
}
init::DepthMapToPCLConverter::~DepthMapToPCLConverter()
{

}

bool init::DepthMapToPCLConverter::connect()
{
    velodyne.getDepthMapPort().connectTo(converter.getConcreteProxy()->depth_map, RTT::ConnPolicy::buffer(10));
    return init::PointCloudProvider::connect();
}

OutputProxyPort< base::samples::Pointcloud >& init::DepthMapToPCLConverter::getPointCloudPort()
{
    return converter.getConcreteProxy()->pointcloud;
}
