#pragma once

#include <lib_init/Base.hpp>
#include <orocos_cpp/Deployment.hpp>
#include <mars/proxies/TaskForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class Simulator : public Base
{
protected:
public:
    Simulator(const std::string& simTaskName, const std::shared_ptr< orocos_cpp::Deployment >& simDeployment);
    
    DependentTask<mars::proxies::Task> simulator;
};
}
