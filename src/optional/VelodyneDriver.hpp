#pragma once

#include <lib_init/Base.hpp>
#include <base/samples/DepthMap.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <velodyne_lidar/proxies/LaserScanner.hpp>

namespace init
{

class VelodyneDriver : public Base {
protected:
    virtual bool connect();

public:
    VelodyneDriver(const std::string &velodyneTaskName);
    virtual ~VelodyneDriver() {};
    DependentTask< velodyne_lidar::proxies::LaserScanner > velodyneTask;
    OutputProxyPort< base::samples::DepthMap >& getLaserScansPort();
};

}