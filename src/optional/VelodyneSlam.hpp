#pragma once

#include <lib_init/Base.hpp>
#include "VelodyneDriver.hpp"

namespace graph_slam {
     namespace proxies {
         class VelodyneSLAM;
     }
}

namespace init
{

class VelodyneSlamDriver : public Base {
protected:
    VelodyneDriver &velodyne;

public:
    DependentTask< graph_slam::proxies::VelodyneSLAM > velodyneSlamTask;
    VelodyneSlamDriver(VelodyneDriver &vd, const std::string &velodyneSlamTaskName);
    virtual bool connect();
    OutputProxyPort< base::samples::RigidBodyState >& getPoseSamplesPort();
};

}