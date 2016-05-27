#include "VelodyneSlam.hpp"

#include <graph_slam/proxies/VelodyneSLAM.hpp>

namespace init
{

VelodyneSlam::VelodyneSlam(VelodyneDriver &vd, const std::string &velodyneSlamTaskName)
    : Base("VelodyneSlam")
    , velodyne(&vd)
    , simVelodyne(nullptr)
    , velodyneSlamTask(this, velodyneSlamTaskName, "graph_slam::VelodyneSLAM")
{
    registerDependency(*velodyne);
}

VelodyneSlam::VelodyneSlam(SimVelodyneDriver& vd, const std::string& velodyneSlamTaskName)
    : Base("VelodyneSlam")
    , velodyne(nullptr)
    , simVelodyne(&vd)
    , velodyneSlamTask(this, velodyneSlamTaskName, "graph_slam::VelodyneSLAM")
{
    registerDependency(*simVelodyne);

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


}