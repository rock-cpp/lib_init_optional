#include "Init.hpp"
#include <orocos_cpp/Spawner.hpp>
#include <orocos_cpp/PluginHelper.hpp>
#include <orocos_cpp/LoggingHelper.hpp>

Init::Init(orocos_cpp::TransformerHelper &trHelper, orocos_cpp::ConfigurationHelper &confHelper, init::Base &toStart, state_machine::State *success) : State("Init", success), toStart(&toStart), trHelper(trHelper), confHelper(confHelper)
{
    loggingActive = false;
}

Init::~Init()
{

}


void Init::enter(const state_machine::State* lastState)
{

}

void Init::activateLogging(const std::vector<std::string> &excludeList)
{
    this->excludeList = excludeList;
    loggingActive = true;
}


void Init::executeFunction()
{
    std::cout << "Init" << std::endl;
    std::cout << "Inits with dependencies to start :" << std::endl;
    
    printDependencies(*toStart, 0);
    
    
    std::vector<orocos_cpp::Deployment *> startedDpl;
    startDeploymentRecursive(*toStart, startedDpl);

    orocos_cpp::Spawner &spawner(orocos_cpp::Spawner::getInstace());

    spawner.waitUntilAllReady(base::Time::fromSeconds(5.0));

    std::vector<init::Base *> started;

    startTasksRecursive(*toStart, started);

    if(loggingActive)
    {
        orocos_cpp::LoggingHelper lHelper;
    
        lHelper.logTasks(excludeList);
    }
    
    std::cout << "Init Done" << std::endl;
    
    finish();
}

void Init::exit()
{

}

template <class T>
bool contains(T *searched, const std::vector<T *> &vec)
{
    for(const T *t: vec)
    {
        if(t == searched )
            return true;
    }
    
    return false;
}

bool Init::startDeploymentRecursive(init::Base& toStart, std::vector<orocos_cpp::Deployment *> &started)
{
    //start all dependencies
    for(init::Base *dep : toStart.getDependencies())
    {
        startDeploymentRecursive(*dep, started);
    }

    orocos_cpp::Spawner &spawner(orocos_cpp::Spawner::getInstace());
    orocos_cpp::PluginHelper helper;


    //start all tasks of this unit
    for(init::DependentTaskBase *dtb : toStart.getDependendTasks())
    {
        if(contains(dtb->getDeployment().get(), started))
            continue;
        
        started.push_back(dtb->getDeployment().get());

        std::cout << "Init::startDeploymentRecursive : Starting deployment " << dtb->getDeployment()->getName() << "Pointer is " << dtb->getDeployment() << std::endl;
        for(const std::string &tk : dtb->getDeployment()->getNeededTypekits())
        {
            helper.loadTypekitAndTransports(tk);
        }

        spawner.spawnDeployment(dtb->getDeployment().get());
    }

    return true;
}

void Init::printDependencies(init::Base& toStart, int level)
{
    
    for(int i = 0; i < level; i++)
        std::cout << " ";
    
    std::cout << toStart.getName() << std::endl;
    
    //start all dependencies
    for(init::Base *dep : toStart.getDependencies())
    {

        
        printDependencies(*dep, level + 1);
        
    }
    
}

bool Init::startTasksRecursive(init::Base& toStart, std::vector<init::Base *> &started)
{
    for(init::Base *s : started)
    {
        if(s == &toStart)
        {
            return true;
        }
    }


    //start all dependencies
    for(init::Base *dep : toStart.getDependencies())
    {
        bool allreadyStarted = false;
        for(init::Base *s : started)
        {
            if(s == dep)
            {
                allreadyStarted = true;
                break;
            }
        }

        if(allreadyStarted)
            continue;

        startTasksRecursive(*dep, started);
    }

    toStart.initProxies();
    toStart.connect();
    toStart.applyConfig(confHelper);
    toStart.setupTransformer(trHelper);
    toStart.configure();
    toStart.start();

    started.push_back(&toStart);

    return true;
}
