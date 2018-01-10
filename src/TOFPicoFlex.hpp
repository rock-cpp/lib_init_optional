#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/DependentTask.hpp>
#include <tofcamera_picoflex/proxies/TaskForward.hpp>
#include <lib_init/DistanceImageProvider.hpp>

namespace init 
{

class TOFPicoFlex : public DistanceImageProvider
{
public:
    TOFPicoFlex(const std::string& taskName);
    
    virtual OutputProxyPort<base::samples::DistanceImage> &getDistanceImagePort();
    
    DependentTask<tofcamera_picoflex::proxies::Task> driver;
};

}

