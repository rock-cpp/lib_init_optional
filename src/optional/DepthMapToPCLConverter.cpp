#include "DepthMapToPCLConverter.hpp"

init::DepthMapToPCLConverter::DepthMapToPCLConverter(init::VelodyneDriver& velodyne, const std::string &converterTaskName): 
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
    velodyne.velodyneTask.getConcreteProxy()->laser_scans.connectTo(converter.getConcreteProxy()->depth_map, RTT::ConnPolicy::buffer(10));
    return init::Base::connect();
}

OutputProxyPort< base::samples::Pointcloud >& init::DepthMapToPCLConverter::getPointCloudPort()
{
    return converter.getConcreteProxy()->cloud;
}
