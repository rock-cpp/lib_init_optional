#include "VelodyneSlam.hpp"

#include <graph_slam/proxies/VelodyneSLAM.hpp>
#include <velodyne_lidar/proxies/LaserScanner.hpp>

namespace init
{

VelodyneSlam::VelodyneSlam(VelodyneDriver &vd, const std::string &velodyneSlamTaskName)
    : PositionProvider("VelodyneSlam")
    , velodyne(&vd)
    , simVelodyne(nullptr)
    , velodyneSlamTask(this, velodyneSlamTaskName)
{
    registerDependency(*velodyne);
}

VelodyneSlam::VelodyneSlam(SimVelodyneDriver& vd, const std::string& velodyneSlamTaskName)
    : PositionProvider("VelodyneSlam")
    , velodyne(nullptr)
    , simVelodyne(&vd)
    , velodyneSlamTask(this, velodyneSlamTaskName)
{
    registerDependency(*simVelodyne);

}

VelodyneSlam::~VelodyneSlam()
{

}

bool VelodyneSlam::connect()
{
    if(velodyne)
    {
        velodyne->getLaserScansPort().connectTo(velodyneSlamTask.getConcreteProxy()->lidar_samples, RTT::ConnPolicy::buffer(50));
    }
    if(simVelodyne)
    {
        simVelodyne->velodyneTask.getConcreteProxy()->pointcloud.connectTo(velodyneSlamTask.getConcreteProxy()->simulated_pointcloud, RTT::ConnPolicy::buffer(50));
    }
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& VelodyneSlam::getPositionSamples()
{
    return velodyneSlamTask.getConcreteProxy()->pose_samples;
}


}