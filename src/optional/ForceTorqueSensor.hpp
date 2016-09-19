#pragma once

#include <lib_init/Base.hpp>
#include <ndlcom_force_torque_sensor/proxies/Task.hpp>
#include "NDLComSerial.hpp"

namespace init
{
class ForceTorqueSensor : public Base {
protected:
    NDLComSerial &ndlcomSerial;

public:
    DependentTask< ndlcom_force_torque_sensor::proxies::Task > forceTorqueSensorTask;

    ForceTorqueSensor(NDLComSerial &ndlcomSerial, const std::string &forceTorqueSensorTaskName);
    virtual bool connect();
};

}
