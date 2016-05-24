#include "NDLComSerial.hpp"
#include <serial_ndlcom/proxies/Task.hpp>

namespace init 
{

NDLComSerial::NDLComSerial(const std::string &receiverTaskName, const std::string &senderTaskName) 
    : Base("NDLComSerial")
    , serial_ndlcomReceiver(this, receiverTaskName, "serial_ndlcom::Task")
    , serial_ndlcomSender(this, senderTaskName, "serial_ndlcom::Task")
{

}
    
}
