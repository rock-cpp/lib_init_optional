#pragma once

#include <string>
#include <vector>
namespace init
{
    class Base;
}

namespace RTT
{
    class TaskContext;
}

namespace log_replay
{

class ReplayPortBase;
    
class ReplayTask 
{
    std::string taskName;
    RTT::TaskContext *proxy;
    
    std::vector<ReplayPortBase *> ports;
public:
    ReplayTask(init::Base* parent, const std::string& taskName);
    virtual ~ReplayTask();
    
    RTT::TaskContext* getProxy();
};

}
