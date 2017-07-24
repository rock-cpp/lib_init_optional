#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/DependentTask.hpp>
#include <tofcamera_picoflex/proxies/Task.hpp>
#include <lib_init/PointCloudProvider.hpp>

namespace init 
{

class TOFPicoFlex : public PointCloudProvider
{
public:
    TOFPicoFlex(const std::string& taskName);
    
    virtual OutputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
    
    DependentTask<tofcamera_picoflex::proxies::Task> driver;
};

}

