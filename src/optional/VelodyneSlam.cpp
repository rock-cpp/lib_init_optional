#include "VelodyneSlam.hpp"

#include <graph_slam/proxies/VelodyneSLAM.hpp>

namespace init
{

VelodyneSlam::VelodyneSlam(VelodyneDriver &vd, const std::string &velodyneSlamTaskName)
    : Base("VelodyneSlam")
    , velodyne(vd)
    , velodyneSlamTask(this, velodyneSlamTaskName, "graph_slam::VelodyneSLAM")
{
    registerDependency(velodyne);
}

bool VelodyneSlam::connect()
{
    velodyne.getLaserScansPort().connectTo(velodyneSlamTask.getConcreteProxy()->lidar_samples);
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& VelodyneSlam::getPoseSamplesPort()
{
    return velodyneSlamTask.getConcreteProxy()->pose_samples;
}

InputProxyPort< base::samples::RigidBodyState >& VelodyneSlam::getOdometrySamplesPort()
{
    return velodyneSlamTask.getConcreteProxy()->odometry_samples;
}

OutputProxyPort< graph_slam::PoseProviderUpdate >& VelodyneSlam::getPoseProviderUpdatePort()
{
    return velodyneSlamTask.getConcreteProxy()->pose_provider_update;
}

InputProxyPort< base::samples::DepthMap >& VelodyneSlam::getLidarSamplesPort()
{
    return velodyneSlamTask.getConcreteProxy()->lidar_samples;
}

OutputProxyPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& VelodyneSlam::getEnvireMapPort()
{
    return velodyneSlamTask.getConcreteProxy()->envire_map;
}

}