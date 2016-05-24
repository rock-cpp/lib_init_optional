#include "Simulator.hpp"

#include <mars/proxies/Task.hpp>

namespace init
{

Simulator::Simulator(const std::string &simTaskName, boost::shared_ptr<orocos_cpp::Deployment> &simDeployment) : Base("Simulator"), simulator(this, simTaskName, "mars::Task")
{
    simulator.setDeployment(simDeployment);
}

}
