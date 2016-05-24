#include "NDLComJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>

#include <serial_ndlcom/proxies/Task.hpp>
#include <ndlcom_device_driver/proxies/NDLComJointDriverBaseTask.hpp>

namespace init
{
 
NDLComJointDriver::NDLComJointDriver(NDLComSerial &serial, const std::string &jointTaskName) 
    : JointDriver("NDLComJointDriver")
    , serial(serial)
    , jointDriver(this, jointTaskName, "ndlcom_wheelmodules::WheelModuleTask")
{
    registerDependency(serial);
}

bool NDLComJointDriver::connect()
{
    jointDriver.getConcreteProxy()->ndlcom_message_out.connectTo(serial.serial_ndlcomSender.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(40));
    serial.serial_ndlcomReceiver.getConcreteProxy()->ndlcom_message_out.connectTo(jointDriver.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(40));
    return JointDriver::connect();
}

bool NDLComJointDriver::start()
{
    bool ret = Base::start();
    
    jointDriver.getConcreteProxy()->addConfigBitsSet( "BLDCJoint", "CONFIG", std::vector<std::string>({"RESET_ERRORS"}), std::vector<std::string>() );
    jointDriver.getConcreteProxy()->enable();
    
    return ret;
}


InputProxyPort< base::commands::Joints >& NDLComJointDriver::getCommandPort()
{
    return jointDriver.getConcreteProxy()->joints_command;
}

OutputProxyPort< base::samples::Joints >& NDLComJointDriver::getStatusPort()
{
    return jointDriver.getConcreteProxy()->joints_status;
}

}