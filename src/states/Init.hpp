#pragma once

#include <state_machine/State.hpp>
#include "../Base.hpp"
#include <orocos_cpp/TransformerHelper.hpp>

class Init : public state_machine::State
{
public:
    Init(orocos_cpp::TransformerHelper &trHelper, orocos_cpp::ConfigurationHelper &confHelper, init::Base &toStart, state_machine::State *success);
    virtual ~Init();

    virtual void init() {};
    virtual void enter(const State* lastState);
    virtual void executeFunction();
    virtual void exit();
    
    void activateLogging(const std::vector< std::string >& excludeList = std::vector<std::string>());

protected:
    init::Base *toStart;
    bool startDeploymentRecursive(init::Base &toStart, std::vector<orocos_cpp::Deployment *> &started);
    bool startTasksRecursive(init::Base &toStart, std::vector<init::Base *> &started);
    
    void printDependencies(init::Base &toStart, int level);
    
    orocos_cpp::TransformerHelper &trHelper;
    orocos_cpp::ConfigurationHelper &confHelper;

    bool loggingActive;
    std::vector<std::string> excludeList;
};
