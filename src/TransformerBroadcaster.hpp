#pragma once

#include "Base.hpp"
#include <transformer/proxies/Task.hpp>
#include <smurf/Robot.hpp>
#include "DependentTask.hpp"

namespace init {

class TransformerBroadcaster : public init::Base
{
    const smurf::Robot &robot;
public:
    TransformerBroadcaster(const std::string &taskName, const smurf::Robot &robot);
    DependentTask<transformer::proxies::Task> broadcaster;
    
    virtual bool start();
};
    
}


