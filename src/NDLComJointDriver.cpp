#include "NDLComJointDriver.hpp"
#include <orocos_cpp/Spawner.hpp>
#include <ndlcom_device_driver/proxies/JointBaseTask.hpp>

#include <serial_ndlcom/proxies/Task.hpp>

namespace init
{
 
NDLComJointDriver::NDLComJointDriver(NDLComSerial &serial, const std::string &jointTaskName) 
    : JointDriver("NDLComJointDriver")
    , serial(serial)
    , jointDriver(DependentTask<ndlcom_device_driver::proxies::JointBaseTask>::getInstance(this, jointTaskName))
{
    registerDependency(serial);
}

bool NDLComJointDriver::connect()
{
    jointDriver.getConcreteProxy()->ndlcom_message_out.connectTo(serial.serial_ndlcom.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(40));
    serial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(jointDriver.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(40));
    return JointDriver::connect();
}

bool NDLComJointDriver::configure()
{
    jointDriver.getConcreteProxy()->addConfigBitsSet( "WheelModule", "CONFIG", std::vector<std::string>({"RESET_ERRORS"}), std::vector<std::string>() );
    
    return JointDriver::configure();
}

bool NDLComJointDriver::start()
{
    bool ret = Base::start();
    
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
