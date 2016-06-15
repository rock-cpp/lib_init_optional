#include "Slam3d.hpp"

init::Slam3d::Slam3d(init::PositionProvider& odometry, init::PointCloudProvider& pclProv, const std::string &mapperTaskName): 
    PositionProvider("Slam3d")
    , Base("Slam3d")
    , odometry(odometry)
    , pclProv(pclProv)
    , mapper(this, mapperTaskName)
{
    registerDependency(odometry);
    registerDependency(pclProv);
}

init::Slam3d::~Slam3d()
{

}

bool init::Slam3d::connect()
{
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& init::Slam3d::getPositionSamples()
{
    return mapper.getConcreteProxy()->map2robot;
}
