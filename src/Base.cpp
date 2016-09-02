#include "Base.hpp"
#include <rtt/transports/corba/TaskContextProxy.hpp>
#include "DependentTask.hpp"

namespace init
{

Base::Base(const std::string &name) : name(name)
{

}

Base::~Base()
{

}

void Base::registerDependency(Base& dependency)
{
    if(&dependency == nullptr)
        throw std::runtime_error("init::Base::registerDependency: Error, tried to register a nullptr on init object with name '" + name + "'");
    
    dependencies.push_back(&dependency);
}

void Base::registerTask(DependentTaskBase* task)
{
    if(task == nullptr)
        throw std::runtime_error("init::Base::registerTask: Error, tried to register a nullptr on init object with name '" + name + "'");
        
    dependendTasks.push_back(task);

}

void Base::initProxies()
{
    for(DependentTaskBase*  &t: dependendTasks)
    {
        t->getProxy();
    }
}

bool Base::connect()
{
    return true;
}

bool Base::applyConfig(orocos_cpp::ConfigurationHelper& confHelper)
{
    for(DependentTaskBase* t: dependendTasks)
    {
        if(!confHelper.applyConfig(t->getProxy(), t->getConfig()))
        {
            std::string msg("init::Base::Failed to applyConfig [");
            for(const std::string &conf: t->getConfig())
                msg += conf + ", ";
            msg += "] for Task " + t->getTaskName();
            
            std::cout << msg << std::endl;
            
            throw std::runtime_error(msg);
        }
    }
        
    return true;
}

bool Base::setupTransformer(orocos_cpp::TransformerHelper& trHelper)
{
    for(DependentTaskBase* t: dependendTasks)
    {
        if(!trHelper.configureTransformer(t->getProxy()))
        {
            throw std::runtime_error("init::Base::Failed to configure transformer for task " + t->getTaskName());
        }
    }
    return true;
}


bool Base::configure()
{
    for(DependentTaskBase* t: dependendTasks)
    {
        std::cout << "init::Base::Configuring " << t->getTaskName() << std::endl;
        if(!t->getProxy()->configure())
        {
            std::string config = "[";
            for(auto conf: t->getConfig())
            {
                config += conf + ", ";
            }
            config += "]";
            throw std::runtime_error("init::Base::Failed to configure task " + t->getTaskName() + " with configuration " + config);
        }

        std::cout << "init::Base::Configured " << t->getTaskName() << std::endl;

    }
    return true;
}

bool Base::start()
{
    for(DependentTaskBase* t: dependendTasks)
    {
        if(!t->getProxy()->start())
        {
            throw std::runtime_error("init::Base::Failed to start task " + t->getTaskName());
        }
        std::cout << "init::Base::Started " << t->getTaskName() << std::endl;

    }

    return true;
}
//
// // void Base::exit()
// // {
// //     msg << "Leaving init state ...\n";
// // };
//
// bool Base::stop()
// {
//     for(TaskWithConfig &t: allTasks)
//     {
//         if(!t.proxy->stop())
//         {
//             throw std::runtime_error("Base::Failed to stop task " + t.proxy->getName());
//         }
//         std::cout << "Base::Stopped " << t.proxy->getName() << std::endl;
//     }
//
//     return true;
// }
}
