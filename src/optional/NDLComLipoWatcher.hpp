#pragma once

#include <lib_init/Base.hpp>
#include <ndlcom_lipo_watcher/proxies/TaskForward.hpp>
#include "NDLComSerial.hpp"
#include <lib_init/DependentTask.hpp>

namespace init
{
class NDLComLipoWatchter : public Base {
protected:
    NDLComSerial &ndlcomSerial;

public:
    DependentTask<ndlcom_lipo_watcher::proxies::Task> watcherTask;

    NDLComLipoWatchter(NDLComSerial &ndlcomSerial, const std::string &taskname);
    virtual bool connect();
};

}
