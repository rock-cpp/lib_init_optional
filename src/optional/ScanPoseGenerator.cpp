#include "ScanPoseGenerator.hpp"


namespace init
{

ScanPoseGenerator::ScanPoseGenerator(const std::string& scanPoseGeneratorName)
    : Base("ScanPoseGenerator")
    , scanPoseGeneratorTask(this, scanPoseGeneratorName)
{
    
}


bool ScanPoseGenerator::connect()
{
    return init::Base::connect();
}


}