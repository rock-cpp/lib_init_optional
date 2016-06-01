#include "PGPGSampler.hpp"


namespace init
{

PGPGSampler::PGPGSampler(const string& scanPoseGeneratorName, const string& graspPoseGeneratorName, const string& graspOffsetGeneratorName, const string& introspectionName)
    : Base("PGPGSampler")
    , scanPoseGeneratorTask(this, scanPoseGeneratorName)
    , graspPoseGeneratorTask(this, graspPoseGeneratorName)
    , graspOffsetGeneratorTask(this, graspOffsetGeneratorName)
    , introspectionTask(this, introspectionName)
{
    
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
    return init::Base::connect();
}


}