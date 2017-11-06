#include "LocalTSDFMapper.hpp"

using namespace init;

LocalTSDFMapper::LocalTSDFMapper(PointCloudProvider* point_cloud, DistanceImageProvider* distance_image1, DistanceImageProvider* distance_image2, MLSProvider* slam, const std::string& mapperTaskName) :
    Base("LocalTSDFMapper")
    , MLSPrecalculatedProvider("LocalTSDFMapper")
    , distance_image1(distance_image1)
    , distance_image2(distance_image2)
    , point_cloud(point_cloud)
    , slam(slam)
    , local_mapper(this, mapperTaskName)
{
    if(point_cloud)
        registerDependency(*point_cloud);
    if(distance_image1)
        registerDependency(*distance_image1);
    if(distance_image2)
        registerDependency(*distance_image2);
    if(slam)
        registerDependency(*slam);
}

LocalTSDFMapper::~LocalTSDFMapper()
{

}

bool LocalTSDFMapper::connect()
{
    if(point_cloud)
        point_cloud->getPointCloudPort().connectTo(local_mapper.getConcreteProxy()->point_cloud);
    if(distance_image1)
        distance_image1->getDistanceImagePort().connectTo(local_mapper.getConcreteProxy()->distance_image1);
    if(distance_image2)
        distance_image2->getDistanceImagePort().connectTo(local_mapper.getConcreteProxy()->distance_image2);
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
