#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <pgpg_sampler/proxies/GraspPoseGenerator.hpp>

namespace init
{

class GraspPoseGenerator : public Base {

    
public:
    GraspPoseGenerator(const std::string &graspPoseGeneratorName);
    virtual bool connect();
    
    DependentTask<pgpg_sampler::proxies::GraspPoseGenerator> graspPoseGeneratorTask;
};

}