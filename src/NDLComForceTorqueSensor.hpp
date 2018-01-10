#pragma once

#include <lib_init/Base.hpp>
#include <ndlcom_force_torque_sensor/proxies/TaskForward.hpp>
#include "NDLComSerial.hpp"
#include <lib_init/ForceTorqueSensor.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{
class NDLComForceTorqueSensor : public ForceTorqueSensor {
protected:
    NDLComSerial &ndlcomSerial;

public:
    DependentTask< ndlcom_force_torque_sensor::proxies::Task > forceTorqueSensorTask;

    NDLComForceTorqueSensor(NDLComSerial &ndlcomSerial, const std::string &forceTorqueSensorTaskName);
    virtual bool connect();
    virtual OutputProxyPort<base::samples::Wrenches> &getStatusPort();
};

}
