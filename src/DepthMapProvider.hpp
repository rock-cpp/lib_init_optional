#pragma once

#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/DepthMap.hpp>
#include <lib_init/Base.hpp>

FW_DECLARE_TYPE(base::samples::DepthMap)

namespace init
{

class DepthMapProvider : public Base
{
public:
    DepthMapProvider(const std::string& name): Base(name) {};
    virtual ~DepthMapProvider() {};
    virtual OutputProxyPort<base::samples::DepthMap> &getDepthMapPort() = 0;
};
}
