#include "GraspOffsetGenerator.hpp"


namespace init
{

GraspOffsetGenerator::GraspOffsetGenerator(const std::string& graspOffsetGeneratorName)
    : Base("GraspOffsetGenerator")
    , graspOffsetGeneratorTask(this, graspOffsetGeneratorName)
{
    
}


bool GraspOffsetGenerator::connect()
{
    return init::Base::connect();
}


}