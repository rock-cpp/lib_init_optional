#include "LateralOdometry.hpp"
#include <odometry/proxies/LatOdom.hpp>

init::LateralOdometry::LateralOdometry(const std::string& odometryName, init::JointDriver& jointDispatcher, init::IMUDriver& imu)
    : Base("LateralOdometry")
    , PositionProvider("LateralOdometry")
    , joints(jointDispatcher)
    , imu(imu)
    , lateralOdometry(DependentTask<odometry::proxies::LatOdom>::getInstance(this, odometryName))
{
    registerDependency(jointDispatcher);
    registerDependency(imu);
}

init::LateralOdometry::~LateralOdometry()
{

}

bool init::LateralOdometry::connect()
{
    joints.getStatusPort().connectTo(lateralOdometry.getConcreteProxy()->actuator_samples);
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& init::LateralOdometry::getPositionSamples()
{
    return lateralOdometry.getConcreteProxy()->odometry_samples;
}
