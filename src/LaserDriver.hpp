#pragma once

#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/LaserScan.hpp>
#include <lib_init/Base.hpp>

namespace init
{

class LaserDriver : public Base
{
public:
    LaserDriver(const std::string& name): Base(name) {};
    virtual ~LaserDriver() {};
    virtual OutputProxyPort<base::samples::LaserScan> &getLaserReadingsPort() = 0;
};
}
