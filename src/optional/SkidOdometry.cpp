#include "SkidOdometry.hpp"

init::SkidOdometry::SkidOdometry(const std::string& odometryName, init::JointDriver& jointDispatcher, init::IMUDriver& imu)
    : Base("SkidOdometry")
    , joints(jointDispatcher)
    , imu(imu)
    , skidOdometry(this, odometryName, "odometry::Skid")
{
    registerDependency(jointDispatcher);
    registerDependency(imu);
}

bool init::SkidOdometry::connect()
{
    joints.getStatusPort().connectTo(skidOdometry.getConcreteProxy()->actuator_samples);
    
    return init::Base::connect();
}
