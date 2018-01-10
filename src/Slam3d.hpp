#pragma once

#include <lib_init/PositionProvider.hpp>
#include <lib_init/PointCloudProvider.hpp>
#include <slam3d/proxies/PointcloudMapperForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class Slam3d : public PositionProvider
{
    PointCloudProvider &pclProv;

public:
    Slam3d(PositionProvider &odometry, PointCloudProvider &pclProv, const std::string &mapperTaskName);
    Slam3d(PointCloudProvider &pclProv, const std::string &mapperTaskName);
    virtual ~Slam3d();
    
    virtual bool connect();
    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();

    DependentTask<slam3d::proxies::PointcloudMapper> mapper;
};


}