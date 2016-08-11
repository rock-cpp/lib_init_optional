#pragma once

#include <string>
#include <orocos_cpp/Deployment.hpp>
#include <boost/shared_ptr.hpp>
#include <rtt/transports/corba/TaskContextProxy.hpp>

namespace init {

class Base;
    
class DependentTaskBase
{
protected:
    std::string taskName;
    std::string taskModel;
    boost::shared_ptr<orocos_cpp::Deployment> deployment;
    std::vector<std::string> config;

    RTT::corba::TaskContextProxy *proxy;
public:
    DependentTaskBase(Base *parent, const std::string &taskName, const std::string &taskModelName);
    
    virtual ~DependentTaskBase();
    
    const std::string &getTaskName() const
    {
        return taskName;
    }

    const std::string &getModelName() const
    {
        return taskModel;
    }

    void setName(const std::string &newName)
    {
        taskName = newName;
    }
    
    void setDeployment(const boost::shared_ptr<orocos_cpp::Deployment> &newDeployment);

    const boost::shared_ptr<orocos_cpp::Deployment> &getDeployment() const
    {
        return deployment;
    }
    
    const std::vector<std::string> &getConfig() const 
    {
        return config;
    }
    
    void setConfig(const std::vector<std::string> &configs);
    void setConfig(const std::string &config);
    void setConfig(const std::string &config, const std::string &config2);
    void setConfig(const std::string& config, const std::string& config2, const std::string& config3);

    
    virtual RTT::corba::TaskContextProxy *getProxy();
    
};
    
template <class TASK>
class DependentTask : public DependentTaskBase
{
public:
    DependentTask(Base *parent, const std::string &taskName) : DependentTaskBase(parent, taskName, TASK::ModelName)
    {
    }
    
    virtual RTT::corba::TaskContextProxy* getProxy()
    {
        if(!proxy)
            proxy = new TASK(taskName);
        
        return proxy;
    };
    
    TASK* getConcreteProxy()
    {
        if(!proxy)
            proxy = new TASK(taskName);
        
        return static_cast<TASK *>(proxy);
    };
    
    
    
    
};
    
    
}