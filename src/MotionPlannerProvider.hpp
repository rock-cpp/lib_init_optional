#pragma once

#include "Base.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/Trajectory.hpp>

namespace init {

class MotionPlannerProvider : public Base
{
public:
    MotionPlannerProvider(const std::string& name) : Base(name) {};
    
    virtual OutputProxyPort< std::vector<base::Trajectory> > &getTrajectories() = 0;
};

    
}
