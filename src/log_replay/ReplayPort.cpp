#include "ReplayPort.hpp"

log_replay::ReplayPortBase::ReplayPortBase(log_replay::ReplayTask& task, const std::string& portName) :
    task(task), 
    portName(portName)
{

}

log_replay::ReplayPortBase::~ReplayPortBase()
{

}
