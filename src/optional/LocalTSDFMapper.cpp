#include "LocalTSDFMapper.hpp"

using namespace init;

LocalTSDFMapper::LocalTSDFMapper(DepthMapProvider* depth_map, PointCloudProvider* point_cloud, MLSProvider* slam, const std::string& mapperTaskName) :
    Base("LocalTSDFMapper")
    , MLSPrecalculatedProvider("LocalTSDFMapper")
    , point_cloud(point_cloud)
    , depth_map(depth_map)
    , slam(slam)
    , local_mapper(this, mapperTaskName)
{
    if(depth_map)
        registerDependency(*depth_map);
    if(point_cloud)
        registerDependency(*point_cloud);
    if(slam)
        registerDependency(*slam);
}

LocalTSDFMapper::~LocalTSDFMapper()
{

}

bool LocalTSDFMapper::connect()
{
    if(depth_map)
        depth_map->getDepthMapPort().connectTo(local_mapper.getConcreteProxy()->depth_map);
    if(point_cloud)
        point_cloud->getPointCloudPort().connectTo(local_mapper.getConcreteProxy()->pointcloud);
    if(slam)
        slam->getMapPort().connectTo(local_mapper.getConcreteProxy()->global_map);
    return init::Base::connect();
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapPrecalculated > >& LocalTSDFMapper::getMapPort()
{
    return local_mapper.getConcreteProxy()->local_map;
}

bool LocalTSDFMapper::generateMap()
{
    return local_mapper.getConcreteProxy()->generateMap();
}
