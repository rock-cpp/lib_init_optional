#include "LocalTSDFMapper.hpp"

using namespace init;

LocalTSDFMapper::LocalTSDFMapper(DepthMapProvider* depth_map, DistanceImageProvider* distance_image, MLSProvider* slam, const std::string& mapperTaskName) :
    Base("LocalTSDFMapper")
    , MLSPrecalculatedProvider("LocalTSDFMapper")
    , distance_image(distance_image)
    , depth_map(depth_map)
    , slam(slam)
    , local_mapper(this, mapperTaskName)
{
    if(depth_map)
        registerDependency(*depth_map);
    if(distance_image)
        registerDependency(*distance_image);
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
    if(distance_image)
        distance_image->getDistanceImagePort().connectTo(local_mapper.getConcreteProxy()->distance_image);
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
