#pragma once

#include <orocos_cpp_base/ProxyPort.hpp>
#include "Base.hpp"
#include <base/samples/Frame.hpp>

namespace init
{

class CameraDriver : public Base
{
public:
    CameraDriver(const std::string& name) : Base(name) {};
    virtual ~CameraDriver() {};
    virtual OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > &getFramePort() = 0;
};
}
