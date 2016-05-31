#pragma once

#include <lib_init/TraversabilityMapProvider.hpp>
#include "VelodyneSlam.hpp"

namespace traversability {
     namespace proxies {
         class Simple;
     }
}


namespace init
{

class TraversabilitySimple : public TraversabilityMapProvider {
    VelodyneSlam &slam;
    
public:
    DependentTask< traversability::proxies::Simple > traversabilityTask;
    TraversabilitySimple(VelodyneSlam &slam, const std::string &traversabilityTaskName);
    
    virtual OutputProxyPort< RTT::extras::ReadOnlyPointer< envire::BinaryEvents > >& getTraversabilityMapPort();
    virtual bool connect();
};

}