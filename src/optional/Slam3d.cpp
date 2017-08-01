#include "Slam3d.hpp"

init::Slam3d::Slam3d(init::PositionProvider& odometry, init::PointCloudProvider& pclProv, const std::string &mapperTaskName): 
    Base("Slam3d")
    , PositionProvider("Slam3d")
    , pclProv(pclProv)
    , mapper(this, mapperTaskName)
{
    registerDependency(odometry);
    registerDependency(pclProv);
}

init::Slam3d::Slam3d(init::PointCloudProvider& pclProv, const std::string& mapperTaskName) :
    Base("Slam3d"),
    PositionProvider("Slam3d"),
    pclProv(pclProv),
    mapper(this, mapperTaskName)
{
    registerDependency(pclProv);
}

init::Slam3d::~Slam3d()
{

}

bool init::Slam3d::connect()
{
    pclProv.getPointCloudPort().connectTo(mapper.getConcreteProxy()->scan, RTT::ConnPolicy::buffer(20));
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& init::Slam3d::getPositionSamples()
{
    return mapper.getConcreteProxy()->robot2map;
}
