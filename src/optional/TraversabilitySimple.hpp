#pragma once

#include <lib_init/Base.hpp>
#include <envire/core/EventTypes.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>

namespace traversability {
     namespace proxies {
         class Simple;
     }
}

namespace init
{

class TraversabilitySimple : public Base {
protected:

public:
    DependentTask< traversability::proxies::Simple > traversabilityTask;
    TraversabilitySimple(const std::string &traversabilityTaskName);
    virtual bool connect();
    InputProxyPort< RTT::extras::ReadOnlyPointer< ::std::vector< ::envire::BinaryEvent > > >& getMLSMapPort();
    OutputProxyPort< RTT::extras::ReadOnlyPointer< ::std::vector< ::envire::BinaryEvent > > >& getTraversabilityMapPort();
};

}