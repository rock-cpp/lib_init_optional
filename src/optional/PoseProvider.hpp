#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <graph_slam/GraphSlamDebugTypes.hpp>
#include <lib_init/PositionProvider.hpp>
#include <lib_init/VelodyneSlam.hpp>

namespace localization {
     namespace proxies {
         class PoseProvider;
     }
}

namespace init
{

class PoseProvider : public PositionProvider {
protected:
    VelodyneSlam &slam;
    PositionProvider &odometry;
    
public:
    DependentTask< localization::proxies::PoseProvider > poseProviderTask;
    PoseProvider(VelodyneSlam &slam, PositionProvider &odometry, const std::string &poseProviderTaskName);
    virtual bool connect();
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}