#include "CommonReplay.hpp"
#include <rtt/transports/corba/TaskContextServer.hpp>
#include <state_machine/Config.hpp>
#include <lib_config/Bundle.hpp>
#include "../Container.hpp"
#include "../InitHelper.hpp"

namespace log_replay
{
CommonReplay::CommonReplay(int argc, char** argv) : argc(argc), argv(argv)
{
    RTT::corba::TaskContextServer::InitOrb(argc, argv);
        
    loggingActive = false;

    for (int i = 0; i<argc; i++)
    {
        if(strcmp(argv[i], "log") == 0)
        {
            loggingActive = true;
            std::cout << "Logging enabled" << std::endl;
        }
    }
    //Initialize the config
    //FIXME this config thing is shitty
    (state_machine::Config::getConfig(libConfig::Bundle::getInstance().getConfigurationDirectory() + "../taskmanagement.yml"));
}


int CommonReplay::runCommon(const smurf::Robot &robot, const std::vector< init::Base* >& toInit)
{
    init::Container all(toInit); 
    orocos_cpp::ConfigurationHelper configHelper;
    orocos_cpp::TransformerHelper transformerHelper(robot);

    InitHelper initializer(transformerHelper, configHelper);
    
    if(loggingActive)
    {
        initializer.activateLogging(logExcludeList);
    }
        
    initializer.start(all, argc, argv);

    return 0;
}

void CommonReplay::setLoggingExcludes(const std::vector< std::string >& excludeList)
{
    logExcludeList = excludeList;
}
}