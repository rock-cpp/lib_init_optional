#pragma once

#include "Base.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/RigidBodyState.hpp>

FW_DECLARE_TYPE(base::samples::RigidBodyState)

namespace init {

class PositionProvider : public virtual Base

{
public:
    PositionProvider(const std::string& name) : Base(name) {};
    
    virtual OutputProxyPort< ::base::samples::RigidBodyState > &getPositionSamples() = 0;
};

    
}
