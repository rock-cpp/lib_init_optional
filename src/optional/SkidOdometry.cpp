#include "SkidOdometry.hpp"

init::SkidOdometry::SkidOdometry(const std::string& odometryName, init::JointDriver& jointDispatcher, init::IMUDriver& imu)
    : PositionProvider("SkidOdometry")
    , joints(jointDispatcher)
    , imu(imu)
    , skidOdometry(this, odometryName, "odometry::Skid")
{
    registerDependency(jointDispatcher);
    registerDependency(imu);
}

init::SkidOdometry::~SkidOdometry()
{

}

bool init::SkidOdometry::connect()
{
    joints.getStatusPort().connectTo(skidOdometry.getConcreteProxy()->actuator_samples);
    
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& init::SkidOdometry::getPositionSamples()
{
    return skidOdometry.getConcreteProxy()->odometry_samples;
}
