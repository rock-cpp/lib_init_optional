#include "DepthMapToPCLConverter.hpp"
#include <depth_map_preprocessing/proxies/PointcloudConverter.hpp>

init::DepthMapToPCLConverter::DepthMapToPCLConverter(init::DepthMapProvider& velodyne, const std::string &converterTaskName):
    PointCloudProvider("DepthMapToPCLConverter"), 
    velodyne(velodyne), 
    converter(DependentTask<depth_map_preprocessing::proxies::PointcloudConverter>::getInstance(this, converterTaskName))
{
    registerDependency(velodyne);
}
init::DepthMapToPCLConverter::~DepthMapToPCLConverter()
{

}

bool init::DepthMapToPCLConverter::connect()
{
    velodyne.getDepthMapPort().connectTo(converter.getConcreteProxy()->depth_map);
    return init::PointCloudProvider::connect();
}

OutputProxyPort< base::samples::Pointcloud >& init::DepthMapToPCLConverter::getPointCloudPort()
{
    return converter.getConcreteProxy()->pointcloud;
}
