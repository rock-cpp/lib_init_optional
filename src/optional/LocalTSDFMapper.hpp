#pragma once

#include <lib_init/MLSProvider.hpp>
#include <lib_init/DistanceImageProvider.hpp>
#include <lib_init/PointCloudProvider.hpp>
#include <local_tsdf_mapper/proxies/Task.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class LocalTSDFMapper : public MLSPrecalculatedProvider
{
    DistanceImageProvider* distance_image1;
    DistanceImageProvider* distance_image2;
    PointCloudProvider* point_cloud;
    MLSProvider* slam;

public:
    LocalTSDFMapper(PointCloudProvider* point_cloud, DistanceImageProvider* distance_image1, DistanceImageProvider* distance_image2, MLSProvider* slam, const std::string &mapperTaskName);
    LocalTSDFMapper(PointCloudProvider* point_cloud, MLSProvider* slam, const std::string &mapperTaskName) : LocalTSDFMapper(point_cloud, nullptr, nullptr, slam, mapperTaskName) {}
    LocalTSDFMapper(DistanceImageProvider* distance_image, MLSProvider* slam, const std::string &mapperTaskName) : LocalTSDFMapper(nullptr, distance_image, nullptr, slam, mapperTaskName) {}
    virtual ~LocalTSDFMapper();

    virtual bool connect();

    virtual OutputProxyPort<envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated> >& getMapPort();

    /** Calling this operator is optional for the local mapper */
    virtual bool generateMap();

    DependentTask<local_tsdf_mapper::proxies::Task> local_mapper;
};


}
