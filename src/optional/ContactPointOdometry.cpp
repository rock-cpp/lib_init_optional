#include "ContactPointOdometry.hpp"

init::ContactPointOdometry::ContactPointOdometry(const std::string& odometryName, init::BodyContactsProvider& bodyContacts, init::IMUDriver& imu)
    : Base("ContactPointOdometry")
    , PositionProvider("ContactPointOdometry")
    , bodyContacts(bodyContacts)
    , imu(imu)
    , contactPointOdometry(this, odometryName)
{
    registerDependency(bodyContacts);
    registerDependency(imu);
}

init::ContactPointOdometry::~ContactPointOdometry()
{

}

bool init::ContactPointOdometry::connect()
{
    bodyContacts.getBodyContactStates().connectTo(contactPointOdometry.getConcreteProxy()->contact_samples, RTT::ConnPolicy::buffer(100));
    return init::Base::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& init::ContactPointOdometry::getPositionSamples()
{
    return contactPointOdometry.getConcreteProxy()->odometry_samples;
}
