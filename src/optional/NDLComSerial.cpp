#include "NDLComSerial.hpp"
#include <serial_ndlcom/proxies/Task.hpp>

namespace init 
{

NDLComSerial::NDLComSerial(const std::string &taskName) 
    : Base("NDLComSerial")
    , serial_ndlcom(DependentTask<serial_ndlcom::proxies::Task>::getInstance(this, taskName))
{

}
    
}
