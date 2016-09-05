#pragma once

#include <lib_init/Base.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>
#include <maps/grid/MLSMap.hpp>

namespace init
{

class MLSProvider : public virtual Base
{
public:
    MLSProvider(const std::string& name);
    virtual ~MLSProvider();
    
    virtual OutputProxyPort<RTT::extras::ReadOnlyPointer<maps::grid::MLSMapSloped> >& getMapPort() = 0;    
};

}
