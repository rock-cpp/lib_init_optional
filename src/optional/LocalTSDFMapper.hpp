#pragma once

#include <lib_init/MLSProvider.hpp>
#include <lib_init/PointCloudProvider.hpp>
#include <lib_init/DepthMapProvider.hpp>
#include <local_tsdf_mapper/proxies/Task.hpp>

namespace init
{

class LocalTSDFMapper : public MLSPrecalculatedProvider
{
    PointCloudProvider* point_cloud;
    DepthMapProvider* depth_map;
    MLSProvider* slam;

public:
    LocalTSDFMapper(DepthMapProvider* depth_map, PointCloudProvider* point_cloud, MLSProvider* slam, const std::string &mapperTaskName);
    LocalTSDFMapper(DepthMapProvider* depth_map, MLSProvider* slam, const std::string &mapperTaskName) : LocalTSDFMapper(depth_map, NULL, slam, mapperTaskName) {};
    LocalTSDFMapper(PointCloudProvider* point_cloud, MLSProvider* slam, const std::string &mapperTaskName) : LocalTSDFMapper(NULL, point_cloud, slam, mapperTaskName) {};
    virtual ~LocalTSDFMapper();

    virtual bool connect();

    virtual OutputProxyPort<envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated> >& getMapPort();

    /** Calling this operator is optional for the local mapper */
    virtual bool generateMap();

    DependentTask<local_tsdf_mapper::proxies::Task> local_mapper;
};


}