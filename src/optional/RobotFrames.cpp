#include "RobotFrames.hpp"

init::RobotFrames::RobotFrames(const std::string& taskName, const std::vector< init::JointDriver* >& joints) : 
    Base("RobotFrames")
    , joints(joints)
    , robotFrames(this, taskName)
{
    for(JointDriver *d : joints)
    {
        registerDependency(*d);
    }
}

bool init::RobotFrames::connect()
{
    for(JointDriver *d : joints)
    {
        d->getStatusPort().connectTo(robotFrames.getConcreteProxy()->input);
    }
    return init::Base::connect();
}
