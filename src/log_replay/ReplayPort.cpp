#include "ReplayPort.hpp"

log_replay::ReplayPortBase::ReplayPortBase(log_replay::ReplayTask& task, const std::string& portName) :
    task(task), 
    portName(portName)
{
    task.ports.push_back(this);
}

log_replay::ReplayPortBase::~ReplayPortBase()
{

}

const std::string& log_replay::ReplayPortBase::getName() const
{
    return portName;
}
