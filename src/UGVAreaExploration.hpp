#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/DependentTask.hpp>
#include <ugv_nav4d/proxies/AreaExplorationForward.hpp>
#include <lib_init/MLSProvider.hpp>
#include <lib_init/PositionProvider.hpp>

namespace init 
{

    class UGVAreaExploration : public Base
{
    MLSProvider &mlsprovider;
    PositionProvider &poseProv;
public:
    UGVAreaExploration(MLSProvider &mlsprovider, PositionProvider &poseProv, const std::string& taskName);
    virtual ~UGVAreaExploration();
    
    virtual bool connect();
    
    DependentTask<ugv_nav4d::proxies::AreaExploration> explorationPlanner;
};

}


