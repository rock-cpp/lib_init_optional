#pragma once

#include <lib_init/Base.hpp>
#include "VelodyneDriver.hpp"
#include <graph_slam/GraphSlamDebugTypes.hpp>
#include <envire/core/EventTypes.hpp>

namespace graph_slam {
     namespace proxies {
         class VelodyneSLAM;
     }
}

namespace init
{

class VelodyneSlam : public Base {
protected:
    VelodyneDriver &velodyne;

public:
    DependentTask< graph_slam::proxies::VelodyneSLAM > velodyneSlamTask;
    VelodyneSlam(VelodyneDriver &vd, const std::string &velodyneSlamTaskName);
    virtual bool connect();
    OutputProxyPort< base::samples::RigidBodyState >& getPoseSamplesPort();
    InputProxyPort< base::samples::RigidBodyState >& getOdometrySamplesPort();
    OutputProxyPort< graph_slam::PoseProviderUpdate >& getPoseProviderUpdatePort();
    InputProxyPort< base::samples::DepthMap >& getLidarSamplesPort();
    OutputProxyPort< RTT::extras::ReadOnlyPointer< ::std::vector< ::envire::BinaryEvent > > >& getEnvireMapPort();
};

}