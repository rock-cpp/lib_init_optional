#include "UGVAreaExploration.hpp"
#include <lib_init/DependentTask.hpp>
#include <ugv_nav4d/proxies/AreaExploration.hpp>

namespace init 
{

UGVAreaExploration::UGVAreaExploration(MLSProvider& mlsprovider, PositionProvider& poseProv, const std::string& taskName): 
    Base("UGVAreaExploration"),
    mlsprovider(mlsprovider),
    poseProv(poseProv),
    explorationPlanner(DependentTask<ugv_nav4d::proxies::AreaExploration>::getInstance(this, taskName))
{
    registerDependency(mlsprovider);
    registerDependency(poseProv);
}

UGVAreaExploration::~UGVAreaExploration()
{

}

bool UGVAreaExploration::connect()
{
    mlsprovider.getMapPort().connectTo(explorationPlanner.getConcreteProxy()->map);
    poseProv.getPositionSamples().connectTo(explorationPlanner.getConcreteProxy()->pose_samples);
    return init::Base::connect();
}



}