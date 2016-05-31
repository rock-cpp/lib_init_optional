#include "TraversabilitySimple.hpp"

#include <traversability/proxies/Simple.hpp>

namespace init
{

TraversabilitySimple::TraversabilitySimple(const std::string& traversabilityTaskName)
    : Base("TraversabilitySimple"),
      traversabilityTask(this, traversabilityTaskName)
{

}

bool TraversabilitySimple::connect()
{
    return init::Base::connect();
}

InputProxyPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& TraversabilitySimple::getMLSMapPort()
{
    return traversabilityTask.getConcreteProxy()->mls_map;
}

OutputProxyPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& TraversabilitySimple::getTraversabilityMapPort()
{
    return traversabilityTask.getConcreteProxy()->traversability_map;
}
   
}