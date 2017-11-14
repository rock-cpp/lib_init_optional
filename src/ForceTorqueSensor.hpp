#pragma once

#include "Base.hpp"
#include <base/samples/Wrenches.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>

FW_DECLARE_TYPE(base::samples::Wrenches)

namespace init
{

class ForceTorqueSensor : public Base
{
public:
    ForceTorqueSensor(const std::string& name) : Base(name) {};
    virtual ~ForceTorqueSensor() {};
    virtual OutputProxyPort<base::samples::Wrenches> &getStatusPort() = 0;    
};
    
}