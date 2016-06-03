#pragma once

#include <lib_init/Base.hpp>
#include <base/samples/Joints.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>

namespace init {
    class TrajectoryControl : public Base
    {
    public:
        TrajectoryControl(const std::string& name) : Base(name) {};
        virtual OutputProxyPort< base::samples::Joints >& getJointStatusPort() = 0;
    };
}