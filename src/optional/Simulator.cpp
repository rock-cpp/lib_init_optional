#include "Simulator.hpp"

#include <mars/proxies/Task.hpp>

namespace init
{

Simulator::Simulator(const std::string &simTaskName,const boost::shared_ptr<orocos_cpp::Deployment> &simDeployment) 
	: Base("Simulator")
    , PositionProvider("Simulator")
    , MLSProvider("Simulator")	
	, simulator(DependentTask<mars::proxies::Task>::getInstance(this, simTaskName))
{
    simulator.setDeployment(simDeployment);
}

void Simulator::setupMLSSimulation(const base::samples::RigidBodyState &robotPose, const envire::core::SpatioTemporal<maps::grid::MLSMapKalman> &mlsKalman)
{
	simulator.getConcreteProxy()->setupMLSSimulation(robotPose, mlsKalman);
}

void Simulator::setupMLSPrecalculatedSimulation(const base::samples::RigidBodyState &robotPose, const envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated> &mlsPrecalculated)
{
	simulator.getConcreteProxy()->setupMLSPrecSimulation(robotPose, mlsPrecalculated);
}


void Simulator::startSimulation() {
	simulator.getConcreteProxy()->startSimulation();
}

void Simulator::stopSimulation() {
	simulator.getConcreteProxy()->stopSimulation();
}


bool Simulator::connect()
{   
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& Simulator::getPositionSamples()
{
    return simulator.getConcreteProxy()->frame_pose;
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& Simulator::getMapPort()
{
    return simulator.getConcreteProxy()->mls_map;
}

bool Simulator::generateMap()
{ 
    simulator.getConcreteProxy()->getMLSMap();
    return true;
}


mars::SerializedScene Simulator::serializePositions() {
    return simulator.getConcreteProxy()->serializePositions();
}

bool Simulator::loadSerializedPositions(mars::SerializedScene scene) {
    return simulator.getConcreteProxy()->loadSerializedPositions(scene);
}

}
