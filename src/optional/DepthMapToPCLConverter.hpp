#pragma once

#include <lib_init/PointCloudProvider.hpp>
#include <lib_init/DepthMapProvider.hpp>
#include <slam3d/proxies/ScanConverter.hpp>

namespace init 
{

class DepthMapToPCLConverter : public PointCloudProvider
{
    DepthMapProvider &velodyne;
public:
    DepthMapToPCLConverter(DepthMapProvider &velodyne, const std::string &converterTaskName);
    virtual ~DepthMapToPCLConverter();
    virtual bool connect();
    
    virtual OutputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
    DependentTask<slam3d::proxies::ScanConverter> converter;
};

}

