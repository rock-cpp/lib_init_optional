#include "DependentTask.hpp"
#include "Base.hpp"

namespace init 
{

DependentTaskBase::DependentTaskBase(Base *parent, const std::string &taskName, const std::string &taskModelName) : taskName(taskName), taskModel(taskModelName), proxy(nullptr)
{
    config.push_back("default");

    deployment.reset(new orocos_cpp::Deployment(taskModel, taskName));
    parent->registerTask(this);
}

DependentTaskBase::~DependentTaskBase()
{

}

RTT::corba::TaskContextProxy* DependentTaskBase::getProxy()
{
    if(!proxy)
    {
        proxy = RTT::corba::TaskContextProxy::Create(taskName, false);
    }
    
    return proxy;
}


void DependentTaskBase::setConfig(const std::vector< std::string >& configs)
{
    config = configs;
}

void DependentTaskBase::setConfig(const std::string& config1)
{
    config.clear();
    
    config.push_back(config1);
}

void DependentTaskBase::setConfig(const std::string& config1, const std::string& config2)
{
    config.clear();
    
    config.push_back(config1);
    config.push_back(config2);
}

void DependentTaskBase::setConfig(const std::string& config1, const std::string& config2, const std::string& config3)
{
    config.clear();
    
    config.push_back(config1);
    config.push_back(config2);
    config.push_back(config3);
}


}