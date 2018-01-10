#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/DependentTask.hpp>
#include <ugv_nav4d/proxies/PathPlannerForward.hpp>
#include <lib_init/MLSProvider.hpp>
#include <lib_init/MLTraversabilityMapProvider.hpp>

namespace init 
{

class UGVNav4d : public MLTraversabilityMapProvider
{
    MLSProvider &mlsprovider;
public:
    UGVNav4d(MLSProvider &mlsprovider, const std::string& taskName);
    virtual ~UGVNav4d();
    
    virtual bool connect();
  
    virtual OutputProxyPort<envire::core::SpatioTemporal<maps::grid::TraversabilityBaseMap3d>>& getTraversabilityMapPort();
    
    DependentTask<ugv_nav4d::proxies::PathPlanner> planner;
};

}
