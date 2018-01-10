#pragma once

#include <lib_init/Base.hpp>
#include <controldev/proxies/GenericRawToMotion2DForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init {
    
class GenericRawToMotion2D : public Base
{
public:
    GenericRawToMotion2D(const std::string& taskName);
    virtual ~GenericRawToMotion2D() {};
    
    DependentTask<controldev::proxies::GenericRawToMotion2D> converter;
};

}