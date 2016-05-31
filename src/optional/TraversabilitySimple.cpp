#include "TraversabilitySimple.hpp"

#include <traversability/proxies/Simple.hpp>
#include <graph_slam/proxies/VelodyneSLAM.hpp>

namespace init
{

TraversabilitySimple::TraversabilitySimple(VelodyneSlam& slam, const std::string& traversabilityTaskName)
    : TraversabilityMapProvider("TraversabilitySimple")
    , slam(slam)
    , traversabilityTask(this, traversabilityTaskName)
{
    registerDependency(slam);
}

bool TraversabilitySimple::connect()
{
    slam.velodyneSlamTask.getConcreteProxy()->envire_map.connectTo(traversabilityTask.getConcreteProxy()->mls_map);
    return init::Base::connect();
}

OutputProxyPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& TraversabilitySimple::getTraversabilityMapPort()
{
    return traversabilityTask.getConcreteProxy()->traversability_map;
}
   
}