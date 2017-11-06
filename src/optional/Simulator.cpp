#include "Simulator.hpp"

#include <mars/proxies/Task.hpp>

namespace init
{

Simulator::Simulator(const std::string &simTaskName,const boost::shared_ptr<orocos_cpp::Deployment> &simDeployment) 
	: Base("Simulator")
    , PositionProvider("Simulator")
    , MLSProvider("Simulator")	
	, simulator(this, simTaskName)
{
    std::cout << "INIT SIMULATOR: " << (simDeployment.get()) << std::endl;


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


bool Simulator::connect()
{   
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& Simulator::getPositionSamples()
{
    std::cout << "init::Simulator::getPositionSamples()" << std::endl;
    return simulator.getConcreteProxy()->frame_pose;
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& Simulator::getMapPort()
{
    std::cout << "init::Simulator::getMapPort()" << std::endl;    
    return simulator.getConcreteProxy()->mls_map;
    //return OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >();
}

bool Simulator::generateMap()
{
    //simulator.getConcreteProxy()->getMLSMap();
    return true;
}

}
