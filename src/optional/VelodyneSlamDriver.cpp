#include "VelodyneSlamDriver.hpp"

#include <graph_slam/proxies/VelodyneSLAM.hpp>

namespace init
{

VelodyneSlamDriver::VelodyneSlamDriver(VelodyneDriver &vd, const std::string &velodyneSlamTaskName)
    : Base("VelodyneSlamDriver")
    , velodyne(vd)
    , velodyneSlamTask(this, velodyneSlamTaskName, "graph_slam::VelodyneSLAM")
{
    registerDependency(velodyne);
}

bool VelodyneSlamDriver::connect()
{
    velodyne.getLaserScansPort().connectTo(velodyneSlamTask.getConcreteProxy()->lidar_samples);
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& VelodyneSlamDriver::getPoseSamplesPort()
{
    return velodyneSlamTask.getConcreteProxy()->pose_samples;
}

}