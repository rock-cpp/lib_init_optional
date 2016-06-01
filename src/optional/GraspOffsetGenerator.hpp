#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <pgpg_sampler/proxies/GraspOffsetGenerator.hpp>

namespace init
{

class GraspOffsetGenerator : public Base {

    
public:
    GraspOffsetGenerator(const std::string &graspOffsetGeneratorName);
    virtual bool connect();
    
    DependentTask<pgpg_sampler::proxies::GraspOffsetGenerator> graspOffsetGeneratorTask;
};

}