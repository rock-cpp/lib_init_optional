#pragma once

#include "Base.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>

namespace init {

class PositionProvider : public virtual Base
{
public:
    PositionProvider(const std::string& name) : Base(name) {};
    
    virtual OutputProxyPort< ::base::samples::RigidBodyState > &getPositionSamples() = 0;
};

    
}
