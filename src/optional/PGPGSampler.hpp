#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <pgpg_sampler/proxies/ScanPoseGenerator.hpp>
#include <pgpg_sampler/proxies/GraspPoseGenerator.hpp>
#include <pgpg_sampler/proxies/GraspOffsetGenerator.hpp>
#include <pgpg_sampler/proxies/Introspection.hpp>
#include <lib_init/PositionProvider.hpp>
#include <lib_init/TraversabilityMapProvider.hpp>

namespace init
{

class PGPGSampler : public Base {

    PositionProvider &robotPosProvider;
    TraversabilityMapProvider &trMap;
public:
    PGPGSampler(PositionProvider &robotPosProvider, TraversabilityMapProvider &trMap, const std::string &scanPoseGeneratorName, const std::string &graspPoseGeneratorName, const std::string &graspOffsetGeneratorName, const std::string &introspectionName);
    virtual bool connect();
    void setDeployment(boost::shared_ptr<orocos_cpp::Deployment> deployment);
    
    DependentTask<pgpg_sampler::proxies::ScanPoseGenerator> scanPoseGeneratorTask;
    DependentTask<pgpg_sampler::proxies::GraspPoseGenerator> graspPoseGeneratorTask;
    DependentTask<pgpg_sampler::proxies::GraspOffsetGenerator> graspOffsetGeneratorTask;
    DependentTask<pgpg_sampler::proxies::Introspection> introspectionTask;
};

}