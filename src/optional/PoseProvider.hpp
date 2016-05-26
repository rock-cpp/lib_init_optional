#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <graph_slam/GraphSlamDebugTypes.hpp>

namespace localization {
     namespace proxies {
         class PoseProvider;
     }
}

namespace init
{

class PoseProvider : public Base {
protected:
    
public:
    DependentTask< localization::proxies::PoseProvider > poseProviderTask;
    PoseProvider(const std::string &poseProviderTaskName);
    virtual bool connect();
    OutputProxyPort< base::samples::RigidBodyState >& getPoseSamplesPort();
    InputProxyPort< base::samples::RigidBodyState >& getOdometrySamplesPort();
    InputProxyPort< graph_slam::PoseProviderUpdate >& getPoseProviderUpdatePort();
};

}