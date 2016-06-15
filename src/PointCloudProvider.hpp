#pragma once

#include <base/samples/Pointcloud.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include "Base.hpp"

extern template class OutputProxyPort< ::base::samples::Pointcloud >;

namespace init 
{

class PointCloudProvider : public Base
{
public:
    PointCloudProvider(const std::string& name);
    virtual ~PointCloudProvider();
    virtual OutputProxyPort< ::base::samples::Pointcloud > &getPointCloudPort() = 0;

};

}

