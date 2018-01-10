#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <serial_ndlcom/proxies/TaskForward.hpp>

namespace init
{

class NDLComSerial : public Base
{
public:
    NDLComSerial(const std::string &taskName);
    
    DependentTask<serial_ndlcom::proxies::Task> serial_ndlcom;
    
};

}
