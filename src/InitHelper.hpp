#pragma once
#include "Base.hpp"
#include <orocos_cpp/TransformerHelper.hpp>

class ReplayHandler;

class InitHelper
{
    orocos_cpp::TransformerHelper &trHelper;
    orocos_cpp::ConfigurationHelper &confHelper;

    bool loggingActive;
    std::vector<std::string> excludeList;
public:
    InitHelper(orocos_cpp::TransformerHelper &trHelper, orocos_cpp::ConfigurationHelper &confHelper);
    
    bool start(init::Base &toStart);
    bool start(init::Base& toStart, int argc, char** argv);
    
    bool startDeploymentRecursive(init::Base &toStart, std::vector<orocos_cpp::Deployment *> &started);
    bool startReplayRecursive(init::Base &toStart, ReplayHandler &replay);
    bool startTasksRecursive(init::Base &toStart, std::vector<init::Base *> &started);
    
    void printDependencies(init::Base &toStart, int level);
    
    void activateLogging(const std::vector< std::string >& excludeList = std::vector<std::string>());

};


