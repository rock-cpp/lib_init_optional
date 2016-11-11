#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <lib_init/PositionProvider.hpp>

namespace simple_pose_integrator {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class PoseProvider : public PositionProvider {
protected:
    PositionProvider &irregular_pose_provider;
    
public:
    DependentTask< simple_pose_integrator::proxies::Task > poseProviderTask;
    PoseProvider(PositionProvider &irregular_pose_provider, const std::string &poseProviderTaskName);
    virtual bool connect();
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}