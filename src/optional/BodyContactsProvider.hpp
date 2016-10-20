#pragma once

#include <lib_init/Base.hpp>
#include <odometry/ContactState.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>

namespace init {

class BodyContactsProvider : public virtual Base
{
public:
    BodyContactsProvider(const std::string& name) : Base(name) {};
    
    virtual OutputProxyPort< odometry::BodyContactState > &getBodyContactStates() = 0;
};

    
}
