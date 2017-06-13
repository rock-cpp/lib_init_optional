#pragma once
#include <lib_init/DepthMapProvider.hpp>
#include <base/samples/DepthMap.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <depth_map_preprocessing/proxies/OutlierFilter.hpp>

namespace init
{

class OutlierFilter : public DepthMapProvider {
protected:
    virtual bool connect();
    DepthMapProvider &input;
public:
    OutlierFilter(const std::string &taskName, DepthMapProvider &input);
    virtual ~OutlierFilter() {};
    DependentTask< depth_map_preprocessing::proxies::OutlierFilter > filterTask;
    OutputProxyPort< base::samples::DepthMap >& getDepthMapPort();
};

}
