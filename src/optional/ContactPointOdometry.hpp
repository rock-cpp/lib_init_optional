#pragma once

#include <lib_init/PositionProvider.hpp>
#include <odometry/proxies/ContactPointTask.hpp>
#include "BodyContactsProvider.hpp"
#include <lib_init/IMUDriver.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class ContactPointOdometry : public PositionProvider
{
    BodyContactsProvider &bodyContacts;
    IMUDriver &imu;
public:
    ContactPointOdometry(const std::string &odometryName, BodyContactsProvider &bodyContacts, IMUDriver &imu);
    virtual ~ContactPointOdometry();
    virtual bool connect();
    DependentTask<odometry::proxies::ContactPointTask> contactPointOdometry;
    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
};

}

