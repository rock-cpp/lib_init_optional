#include "ReplayTask.hpp"
#include <rtt/transports/corba/TaskContextProxy.hpp>
#include "../Base.hpp"
#include "ReplayPort.hpp"

namespace log_replay
{

ReplayTask::ReplayTask(init::Base* parent, const std::string& taskName) :
    taskName(taskName),
    proxy(nullptr)
{
    parent->registerReplayTask(this);
}

ReplayTask::~ReplayTask()
{
    delete proxy;
}

const std::string& ReplayTask::getName() const
{
    return taskName;
}

const std::vector< ReplayPortBase* > &ReplayTask::getPorts() const
{
    return ports;
}



void ReplayTask::init()
{
    getProxy();
    
    for(auto p: ports)
    {
        p->initPort();
    }
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