#pragma once

#include "Base.hpp"

namespace init {
 
class Container : public Base
{
public:
    Container(const std::vector<Base *> &deps) : Base("Container")
    {
        for(Base *dep : deps)
        {
            registerDependency(*dep);
        }
    }
};
    
}