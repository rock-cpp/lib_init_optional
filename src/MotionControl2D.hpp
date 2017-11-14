#pragma once

#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/CommandSamples.hpp>
#include <lib_init/Base.hpp>

FW_DECLARE_TYPE(base::commands::Motion2D)

namespace init
{

class MotionControl2D : public virtual Base
{
public:
    MotionControl2D(const std::string& name): Base(name) {};
    virtual ~MotionControl2D() {};
    virtual InputProxyPort<base::commands::Motion2D> &getCommand2DPort() = 0;
};
}
