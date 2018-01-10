#pragma once

#include <lib_init/DepthMapProvider.hpp>
#include <base/samples/DepthMap.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <velodyne_lidar/proxies/LaserScannerForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class VelodyneDriver : public DepthMapProvider {
protected:
    virtual bool connect();

public:
    VelodyneDriver(const std::string &velodyneTaskName);
    virtual ~VelodyneDriver() {};
    DependentTask< velodyne_lidar::proxies::LaserScanner > velodyneTask;
    OutputProxyPort< base::samples::DepthMap >& getLaserScansPort();
    OutputProxyPort< base::samples::DepthMap >& getDepthMapPort();
};

}