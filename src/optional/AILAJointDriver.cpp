#include "AILAJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>
#include <serial_ndlcom/proxies/Task.hpp>
#include <ndlcom_aila_joints/proxies/AILAJointTask.hpp>

namespace init
{

AILAJointDriver::AILAJointDriver(init::NDLComSerial& ndlcomSerial, const std::string &AILAJointsTaskName) 
    : JointDriver("AILAJointDriver")
    , ndlcomSerial(ndlcomSerial)
    , jointTask(this, AILAJointsTaskName, new DependentTaskPimplImpl<ndlcom_aila_joints::proxies::AILAJointTask>)
{
    registerDependency(ndlcomSerial);
}

bool AILAJointDriver::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(jointTask.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(200));
    jointTask.getConcreteProxy()->ndlcom_message_out.connectTo(ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(200));
    return init::JointDriver::connect();
}

bool AILAJointDriver::start()
{
    jointTask.getConcreteProxy()->enable();
    return init::JointDriver::start();
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
