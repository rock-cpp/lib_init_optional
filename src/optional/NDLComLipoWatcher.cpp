#include "NDLComLipoWatcher.hpp"
#include <ndlcom_lipo_watcher/proxies/Task.hpp>
#include <serial_ndlcom/proxies/Task.hpp>

namespace init
{
    
NDLComLipoWatchter::NDLComLipoWatchter(NDLComSerial &ndlcomSerial, const std::string &taskname)
     : Base("NDLComLipoWatchter")
     , ndlcomSerial(ndlcomSerial)
     , watcherTask(DependentTask<ndlcom_lipo_watcher::proxies::Task>::getInstance(this, taskname))
{
    registerDependency(ndlcomSerial);
}
     
bool NDLComLipoWatchter::connect()
{
    ndlcomSerial.serial_ndlcom.getConcreteProxy()->ndlcom_message_out.connectTo(watcherTask.getConcreteProxy()->ndlcom_message_in);
    
    return Base::connect();
}

}