#include "ReplayTask.hpp"
#include <rtt/transports/corba/TaskContextProxy.hpp>

namespace log_replay
{

ReplayTask::ReplayTask(init::Base* parent, const std::string& taskName) :
    taskName(taskName),
    proxy(nullptr)
{

}

ReplayTask::~ReplayTask()
{
    delete proxy;
}

RTT::TaskContext* ReplayTask::getProxy()
{
    if(!proxy)
    {
        std::cout << "Trying to connect to " << taskName << std::endl;
        proxy = RTT::corba::TaskContextProxy::Create(taskName);
    }
    
    return proxy;
}


    
}