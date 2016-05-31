#pragma once

#include <lib_init/PositionProvider.hpp>
#include "VelodyneDriver.hpp"
#include "SimVelodyneDriver.hpp"
#include <graph_slam/GraphSlamDebugTypes.hpp>
#include <envire/core/EventTypes.hpp>

namespace graph_slam {
     namespace proxies {
         class VelodyneSLAM;
     }
}

namespace init
{

class VelodyneSlam : public PositionProvider {
protected:
    VelodyneDriver *velodyne;
    SimVelodyneDriver *simVelodyne;
    PositionProvider &odometry;

public:
    DependentTask< graph_slam::proxies::VelodyneSLAM > velodyneSlamTask;
    virtual ~VelodyneSlam();
    VelodyneSlam(VelodyneDriver &vd, PositionProvider &odometry, const std::string &velodyneSlamTaskName);
    VelodyneSlam(SimVelodyneDriver &vd, PositionProvider &odometry, const std::string &velodyneSlamTaskName);
    virtual bool connect();
    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}