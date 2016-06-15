#pragma once

#include <lib_init/TraversabilityMapProvider.hpp>
#include <lib_init/MapProvider.hpp>
#include "VelodyneSlam.hpp"

namespace traversability {
     namespace proxies {
         class Simple;
     }
}


namespace init
{

class TraversabilitySimple : public TraversabilityMapProvider {
    MapProvider &slam;
    
public:
    DependentTask< traversability::proxies::Simple > traversabilityTask;
    TraversabilitySimple(MapProvider &slam, const std::string &traversabilityTaskName);
    
    virtual OutputProxyPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& getTraversabilityMapPort();
    virtual bool connect();
};

}