#include "Simulator.hpp"

#include <mars/proxies/Task.hpp>

namespace init
{

Simulator::Simulator(const std::string &simTaskName,const boost::shared_ptr<orocos_cpp::Deployment> &simDeployment) : Base("Simulator"), simulator(this, simTaskName)
{
    simulator.setDeployment(simDeployment);
}

void Simulator::setupMLSSimulation(const base::samples::RigidBodyState &robotPose, const envire::core::SpatioTemporal<maps::grid::MLSMapKalman> &mlsKalman)
{
	simulator.getConcreteProxy()->setupMLSSimulation(robotPose, mlsKalman);
}


void Simulator::startSimulation() {
	simulator.getConcreteProxy()->startSimulation();
}

void Simulator::stopSimulation() {
	simulator.getConcreteProxy()->stopSimulation();
}

}
