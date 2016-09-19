#include "ForceTorqueSensor.hpp"

#include <serial_ndlcom/proxies/Task.hpp>

namespace init
{
    
ForceTorqueSensor::ForceTorqueSensor(NDLComSerial &ndlcomSerial, const std::string &forceTorqueSensorTaskName)
     : Base("ForceTorqueSensor")
     , ndlcomSerial(ndlcomSerial)
     , forceTorqueSensorTask(this, forceTorqueSensorTaskName)
{
}
     
bool ForceTorqueSensor::connect()
{
    this->ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(forceTorqueSensorTask.getConcreteProxy()->ndlcom_message_in, RTT::ConnPolicy::buffer(300));
    return Base::connect();
}
    
}