#pragma once

#include <lib_init/Base.hpp>
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

class VelodyneSlam : public Base {
protected:
    VelodyneDriver *velodyne;
    SimVelodyneDriver *simVelodyne;

public:
    DependentTask< graph_slam::proxies::VelodyneSLAM > velodyneSlamTask;
    VelodyneSlam(VelodyneDriver &vd, const std::string &velodyneSlamTaskName);
    VelodyneSlam(SimVelodyneDriver &vd, const std::string &velodyneSlamTaskName);
    virtual bool connect();
};

}