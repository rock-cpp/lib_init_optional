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
    friend class ReplayPortBase;
    std::string taskName;
    RTT::TaskContext *proxy;
    
    std::vector<ReplayPortBase *> ports;
public:
    ReplayTask(init::Base* parent, const std::string& taskName);
    virtual ~ReplayTask();
    
    const std::vector<ReplayPortBase *> &getPorts() const;
    const std::string &getName() const;
    
    void init();
    
    RTT::TaskContext* getProxy();
};

}
