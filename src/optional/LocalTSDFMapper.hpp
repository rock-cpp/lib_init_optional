#pragma once

#include <lib_init/MLSProvider.hpp>
#include <lib_init/DistanceImageProvider.hpp>
#include <lib_init/DepthMapProvider.hpp>
#include <local_tsdf_mapper/proxies/Task.hpp>

namespace init
{

class LocalTSDFMapper : public MLSPrecalculatedProvider
{
    DistanceImageProvider* distance_image1;
    DistanceImageProvider* distance_image2;
    DepthMapProvider* depth_map;
    MLSProvider* slam;

public:
    LocalTSDFMapper(DepthMapProvider* depth_map, DistanceImageProvider* distance_image1, DistanceImageProvider* distance_image2, MLSProvider* slam, const std::string &mapperTaskName);
    LocalTSDFMapper(DepthMapProvider* depth_map, MLSProvider* slam, const std::string &mapperTaskName) : LocalTSDFMapper(depth_map, nullptr, nullptr, slam, mapperTaskName) {}
    LocalTSDFMapper(DistanceImageProvider* distance_image, MLSProvider* slam, const std::string &mapperTaskName) : LocalTSDFMapper(nullptr, distance_image, nullptr, slam, mapperTaskName) {}
    virtual ~LocalTSDFMapper();

    virtual bool connect();

    virtual OutputProxyPort<envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated> >& getMapPort();

    /** Calling this operator is optional for the local mapper */
    virtual bool generateMap();

    DependentTask<local_tsdf_mapper::proxies::Task> local_mapper;
};


}
