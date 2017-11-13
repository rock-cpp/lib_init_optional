#include "NDLComCpmbWatcher.hpp"
#include <ndlcom_cpmb_watcher/proxies/Task.hpp>
#include <serial_ndlcom/proxies/Task.hpp>

namespace init
{
    
NDLComCpmbWatcher::NDLComCpmbWatcher(NDLComSerial &ndlcomSerial, const std::string &taskname)
     : Base("NDLComCpmbWatcher")
     , ndlcomSerial(ndlcomSerial)
     , watcherTask(DependentTask<ndlcom_cpmb_watcher::proxies::Task>::getInstance(this, taskname))
{
    registerDependency(ndlcomSerial);
}
     
bool NDLComCpmbWatcher::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(watcherTask.getConcreteProxy()->ndlcom_message_in);
    
    return Base::connect();
}

}