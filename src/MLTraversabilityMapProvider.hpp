#pragma once

#include <lib_init/Base.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <rtt/extras/ReadOnlyPointer.hpp>
#include <maps/grid/TraversabilityMap3d.hpp>
#include <envire_core/items/SpatioTemporal.hpp>

FW_DECLARE_TYPE(envire::core::SpatioTemporal<maps::grid::TraversabilityBaseMap3d>)

namespace init
{

class MLTraversabilityMapProvider : public virtual Base
{
public:
    MLTraversabilityMapProvider(const std::string& name) : Base(name) {}
    virtual ~MLTraversabilityMapProvider() {}
    
    virtual OutputProxyPort<envire::core::SpatioTemporal<maps::grid::TraversabilityBaseMap3d> >& getTraversabilityMapPort() = 0;
};

}
