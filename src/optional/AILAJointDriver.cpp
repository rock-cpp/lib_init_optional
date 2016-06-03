#include "AILAJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>
#include <serial_ndlcom/proxies/Task.hpp>

namespace init
{

AILAJointDriver::AILAJointDriver(init::NDLComSerial& ndlcomSerial, const std::string &AILAJointsTaskName) 
    : JointDriver("AILAJointDriver")
    , jointTask(this, AILAJointsTaskName)
    , ndlcomSerial(ndlcomSerial)
{
    registerDependency(ndlcomSerial);
}

bool AILAJointDriver::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(jointTask.getConcreteProxy()->ndlcom_message_in);
    jointTask.getConcreteProxy()->ndlcom_message_out.connectTo(ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_in);
    return init::Base::connect();
}

InputProxyPort< base::commands::Joints >& AILAJointDriver::getCommandPort()
{
    return jointTask.getConcreteProxy()->joints_command;
}

OutputProxyPort< base::samples::Joints >& AILAJointDriver::getStatusPort()
{
    return jointTask.getConcreteProxy()->joints_status;
}
}
