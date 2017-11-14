#pragma once

#include "Base.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/Trajectory.hpp>

FW_DECLARE_TYPE(std::vector<base::Trajectory>)

namespace init {

class MotionPlannerProvider : public Base
{
public:
    MotionPlannerProvider(const std::string& name) : Base(name) {};
    
    virtual OutputProxyPort< std::vector<base::Trajectory> > &getTrajectories() = 0;
};

    
}
