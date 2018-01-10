#include "UGVNav4d.hpp"
#include <ugv_nav4d/proxies/PathPlanner.hpp>


init::UGVNav4d::UGVNav4d(init::MLSProvider& mlsprovider, const std::string& taskName): 
     Base("UGVNav4d"), MLTraversabilityMapProvider("UGVNav4d")
    , mlsprovider(mlsprovider)
    , planner(DependentTask<ugv_nav4d::proxies::PathPlanner>::getInstance(this, taskName))
{

}

init::UGVNav4d::~UGVNav4d()
{

}


bool init::UGVNav4d::connect()
{
    mlsprovider.getMapPort().connectTo(planner.getConcreteProxy()->map);
    
    return init::Base::connect();
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::TraversabilityBaseMap3d > >& init::UGVNav4d::getTraversabilityMapPort()
{
    return planner.getConcreteProxy()->tr_map;
}
