#include "NDLComForceTorqueSensor.hpp"
#include <ndlcom_force_torque_sensor/proxies/Task.hpp>
#include <serial_ndlcom/proxies/Task.hpp>

namespace init
{
    
NDLComForceTorqueSensor::NDLComForceTorqueSensor(NDLComSerial &ndlcomSerial, const std::string &forceTorqueSensorTaskName)
     : ForceTorqueSensor("ForceTorqueSensor")
     , ndlcomSerial(ndlcomSerial)
     , forceTorqueSensorTask(DependentTask< ndlcom_force_torque_sensor::proxies::Task >::getInstance(this, forceTorqueSensorTaskName))
{
    registerDependency(ndlcomSerial);
}
     
bool NDLComForceTorqueSensor::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(forceTorqueSensorTask.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(300));
    return ForceTorqueSensor::connect();
}
 
OutputProxyPort< base::samples::Wrenches >& NDLComForceTorqueSensor::getStatusPort()
{
    return forceTorqueSensorTask.getConcreteProxy()->ft_values;
}
 
}