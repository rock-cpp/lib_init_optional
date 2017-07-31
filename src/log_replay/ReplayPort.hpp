#pragma once
#include "ReplayTask.hpp"
#include <string>
#include <orocos_cpp_base/ProxyPort.hpp>

namespace log_replay
{

class ReplayPortBase
{
protected:
    ReplayTask &task;
    std::string portName;
    
public:
    ReplayPortBase(ReplayTask &task, const std::string &portName);
    virtual ~ReplayPortBase();
    virtual void initPort() = 0;
    
    const std::string &getName() const;
};

template<typename TYPE>
class ReplayPort : public ReplayPortBase
{
    OutputProxyPort<TYPE> *port;
public:
    ReplayPort(ReplayTask &task, const std::string &portName) : 
    ReplayPortBase(task, portName),
    port(nullptr)
    {
    }
    
    ~ReplayPort() {};
    
    virtual void initPort()
    {
        port = new OutputProxyPort<TYPE>(task.getProxy(), portName);
    }
    
    OutputProxyPort<TYPE> &getPort()
    {
        return *port;
    }
};
}

