#pragma once

#include <lib_init/Base.hpp>
#include <ndlcom_cpmb_watcher/proxies/Task.hpp>
#include "NDLComSerial.hpp"
#include <lib_init/DependentTask.hpp>

namespace init
{
class NDLComCpmbWatcher : public Base {
protected:
    NDLComSerial &ndlcomSerial;

public:
    DependentTask<ndlcom_cpmb_watcher::proxies::Task> watcherTask;

    NDLComCpmbWatcher(NDLComSerial &ndlcomSerial, const std::string &taskname);
    virtual bool connect();
};

}
