#pragma once

#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/CommandSamples.hpp>
#include <lib_init/Base.hpp>

namespace init
{

class MotionControl2DProvider : public virtual Base
{
public:
    MotionControl2DProvider(const std::string& name): Base(name) {};
    virtual ~MotionControl2DProvider() {};
    virtual OutputProxyPort<base::commands::Motion2D> &getCommand2DPort() = 0;
};
}
