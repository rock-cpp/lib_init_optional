#pragma once

#include <lib_init/JointDriver.hpp>
#include "Simulator.hpp"
#include <mars/proxies/JointsForward.hpp>

namespace init
{

class SimJointDriver : public JointDriver
{
public:
    SimJointDriver(Simulator &sim, const std::string &marsJointTaskName);

    virtual OutputProxyPort<base::samples::Joints> &getStatusPort();
    virtual InputProxyPort<base::commands::Joints> &getCommandPort();

    DependentTask<mars::proxies::Joints> jointTask;
};
}
