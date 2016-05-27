#pragma once

#include <lib_init/PositionProvider.hpp>
#include <odometry/proxies/Skid.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/IMUDriver.hpp>

namespace init
{

class SkidOdometry : public PositionProvider
{
    JointDriver &joints;
    IMUDriver &imu;
public:
    SkidOdometry(const std::string &odometryName, JointDriver &joints, IMUDriver &imu);
    virtual ~SkidOdometry();
    virtual bool connect();
    DependentTask<odometry::proxies::Skid> skidOdometry;
    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}

