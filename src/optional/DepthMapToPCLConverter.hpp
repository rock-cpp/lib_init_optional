#pragma once

#include <lib_init/PointCloudProvider.hpp>

#include "VelodyneDriver.hpp"
#include <slam3d/proxies/ScanConverter.hpp>

namespace init 
{

class DepthMapToPCLConverter : public PointCloudProvider
{
    VelodyneDriver &velodyne;
public:
    DepthMapToPCLConverter(VelodyneDriver &velodyne, const std::string &converterTaskName);
    virtual ~DepthMapToPCLConverter();
    virtual bool connect();
    
    virtual OutputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
    DependentTask<slam3d::proxies::ScanConverter> converter;
};

}

