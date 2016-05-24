#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>

namespace serial_ndlcom {
    namespace proxies {
        class Task;
    }
}

namespace init
{

class NDLComSerial : public Base
{
public:
    NDLComSerial(const std::string &receiverTaskName, const std::string &senderTaskName);
    
    DependentTask<serial_ndlcom::proxies::Task> serial_ndlcomReceiver;
    DependentTask<serial_ndlcom::proxies::Task> serial_ndlcomSender;
    
};

}
