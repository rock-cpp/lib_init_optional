#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <pgpg_sampler/proxies/ScanPoseGenerator.hpp>

namespace init
{

class ScanPoseGenerator : public Base {

    
public:
    ScanPoseGenerator(const std::string &scanPoseGeneratorName);
    virtual bool connect();
    
    DependentTask<pgpg_sampler::proxies::ScanPoseGenerator> scanPoseGeneratorTask;
};

}