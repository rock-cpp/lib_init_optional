#pragma once

#include <lib_init/Base.hpp>
#include <ndlcom_lipo_watcher/proxies/Task.hpp>
#include "NDLComSerial.hpp"

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
