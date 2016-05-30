#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/JointDriver.hpp>
#include <lib_init/Base.hpp>
#include "NDLComSerial.hpp"

namespace ndlcom_device_driver {
    namespace proxies {
        class NDLComJointDriverBaseTask;
    }
}

namespace init
{

class NDLComJointDriver : public JointDriver {
    NDLComSerial &serial;
public:
    NDLComJointDriver(NDLComSerial &serial, const std::string &jointTaskName);
    //virtual void initProxies();
    virtual bool connect();
    virtual bool configure();
    virtual bool start();
    
    virtual OutputProxyPort<base::samples::Joints> &getStatusPort();
    virtual InputProxyPort<base::commands::Joints> &getCommandPort();

    DependentTask<ndlcom_device_driver::proxies::NDLComJointDriverBaseTask> jointDriver;
};

}
