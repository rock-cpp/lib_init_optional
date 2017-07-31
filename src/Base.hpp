#pragma once

#include <orocos_cpp/TransformerHelper.hpp>
#include <orocos_cpp/ConfigurationHelper.hpp>
#include <orocos_cpp/Deployment.hpp>
#include "DependentTask.hpp"

namespace RTT {
namespace corba {
class TaskContextProxy;
}
}

namespace log_replay
{
class ReplayTask;
}

namespace init
{

class DependentTaskBase;

class Base
{
    friend class DependentTaskBase;
    friend class log_replay::ReplayTask;
    
private:
    std::string name;
    
public:

    Base(const std::string &name);
    virtual ~Base();

    std::vector<DependentTaskBase *> getDependendTasks()  const
    {
        return dependendTasks;
    }

    std::vector<log_replay::ReplayTask *> getReplayTasks() const
    {
        return replayTasks;
    }
    
    std::vector<Base *> getDependencies() const
    {
        return dependencies;
    };

    void updateDeploymentForTask(const std::string &taskName, orocos_cpp::Deployment *dpl);

    /***
     * Initializes the Proxes, for this Init Object
     * */
    virtual void initProxies();
    
    /***
     * @previous initProxies()
     * @following applyConfig();
     * 
     * Creates the connections between the components of this
     * Init Object.
     * */
    virtual bool connect();
    
    
    /***
     * @previous connect()
     * @following setupTransformer
     * 
     * Applies the configuraton for the dependend tasks of this 
     * Init Object.
     * */
    virtual bool applyConfig(orocos_cpp::ConfigurationHelper &confHelper);

    /***
     * @previous applyConfig
     * @following configure
     * 
     * Sets up the Transformer for the dependend tasks of this Init Object
     * */
    virtual bool setupTransformer(orocos_cpp::TransformerHelper &trHelper);

    /***
     * @previous setupTransformer
     * @following start
     * 
     * Configures the dependend tasks of this Init Object
     * */
    virtual bool configure();

    /***
     * @previous configure
     * @following -
     * 
     * Starts the dependend tasks of this Init Object
     * */
    virtual bool start();
    
    const std::string &getName() {
        return name;
    };
protected:
    void registerTask(DependentTaskBase *task);
    void registerReplayTask(log_replay::ReplayTask *task);
    void registerDependency(Base &dependency);

    std::vector<DependentTaskBase *> dependendTasks;
    std::vector<log_replay::ReplayTask *> replayTasks;
    std::vector<Base *> dependencies;
};


}

