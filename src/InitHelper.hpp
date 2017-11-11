#pragma once
#include <vector>
#include <string>

class ReplayHandler;

namespace orocos_cpp {
    class Deployment;
    class TransformerHelper;
    class ConfigurationHelper;
}

namespace init {
    class Base;
}

class InitHelper
{
    orocos_cpp::TransformerHelper &trHelper;
    orocos_cpp::ConfigurationHelper &confHelper;

    bool loggingActive;
    std::vector<std::string> excludeList;
public:
    InitHelper(orocos_cpp::TransformerHelper &trHelper, orocos_cpp::ConfigurationHelper &confHelper);
    
    bool start(init::Base &toStart);
    bool start(init::Base& toStart, int argc, char** argv, ReplayHandler &replay);
    
    bool startDeploymentRecursive(init::Base &toStart, std::vector<orocos_cpp::Deployment *> &started);
    bool startReplayRecursive(init::Base &toStart, ReplayHandler &replay);
    bool startTasksRecursive(init::Base &toStart, std::vector<init::Base *> &started);
    
    void printDependencies(init::Base &toStart, int level);
    
    void activateLogging(const std::vector< std::string >& excludeList = std::vector<std::string>());

};


