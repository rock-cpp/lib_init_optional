#include "GraspPoseGenerator.hpp"


namespace init
{

GraspPoseGenerator::GraspPoseGenerator(const std::string& graspPoseGeneratorName)
    : Base("GraspPoseGenerator")
    , graspPoseGeneratorTask(this, graspPoseGeneratorName)
{
    
}


bool GraspPoseGenerator::connect()
{
    return init::Base::connect();
}


}