#include "PGPGSampler.hpp"


namespace init
{

PGPGSampler::PGPGSampler(PositionProvider &robotPosProvider, TraversabilityMapProvider &trMap, const string& scanPoseGeneratorName, const string& graspPoseGeneratorName, const string& graspOffsetGeneratorName, const string& introspectionName)
    : Base("PGPGSampler")
    , robotPosProvider(robotPosProvider)
    , trMap(trMap)    
    , scanPoseGeneratorTask(this, scanPoseGeneratorName)
    , graspPoseGeneratorTask(this, graspPoseGeneratorName)
    , graspOffsetGeneratorTask(this, graspOffsetGeneratorName)
    , introspectionTask(this, introspectionName)
{
    registerDependency(robotPosProvider);
    registerDependency(trMap);
}


void PGPGSampler::setDeployment(boost::shared_ptr< orocos_cpp::Deployment > deployment)
{
    scanPoseGeneratorTask.setDeployment(deployment);
    graspPoseGeneratorTask.setDeployment(deployment);
    graspOffsetGeneratorTask.setDeployment(deployment);
    introspectionTask.setDeployment(deployment);
}



bool PGPGSampler::connect()
{
    robotPosProvider.getPositionSamples().connectTo(scanPoseGeneratorTask.getConcreteProxy()->robot_pose);
    trMap.getTraversabilityMapPort().connectTo(scanPoseGeneratorTask.getConcreteProxy()->traversability_map);
    
    robotPosProvider.getPositionSamples().connectTo(graspPoseGeneratorTask.getConcreteProxy()->robot_pose);
    trMap.getTraversabilityMapPort().connectTo(graspPoseGeneratorTask.getConcreteProxy()->traversability_map);
    
    robotPosProvider.getPositionSamples().connectTo(graspOffsetGeneratorTask.getConcreteProxy()->robot_pose);
    trMap.getTraversabilityMapPort().connectTo(graspOffsetGeneratorTask.getConcreteProxy()->traversability_map);
    
    return init::Base::connect();
}


}