#include "Simulator.hpp"

#include <mars/proxies/Task.hpp>

namespace init
{

Simulator::Simulator(const std::__cxx11::string& simTaskName, const std::shared_ptr< orocos_cpp::Deployment >& simDeployment) 
	: Base("Simulator")
	, simulator(DependentTask<mars::proxies::Task>::getInstance(this, simTaskName))
{
    simulator.setDeployment(simDeployment);
}
}
