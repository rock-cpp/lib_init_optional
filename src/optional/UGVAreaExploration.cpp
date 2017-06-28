#include "UGVAreaExploration.hpp"
#include "../DependentTask.hpp"

namespace init 
{

UGVAreaExploration::UGVAreaExploration(MLSProvider& mlsprovider, PositionProvider& poseProv, const std::string& taskName): 
    Base("UGVAreaExploration"),
    mlsprovider(mlsprovider),
    poseProv(poseProv),
    explorationPlanner(this, taskName)
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