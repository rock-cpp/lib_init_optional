#include "CommonReplay.hpp"
#include <rtt/transports/corba/TaskContextServer.hpp>
#include <state_machine/Config.hpp>
#include <lib_config/Bundle.hpp>
#include "states/Init.hpp"
#include "Container.hpp"

CommonReplay::CommonReplay(int argc, char** argv)
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
    state_machine::Config *config = &(state_machine::Config::getConfig(libConfig::Bundle::getInstance().getConfigurationDirectory() + "../taskmanagement.yml"));
}


int CommonReplay::runCommon(const smurf::Robot &robot, const std::vector< init::Base* >& toInit)
{
    init::Container all(toInit); 
    orocos_cpp::ConfigurationHelper configHelper;
    orocos_cpp::TransformerHelper transformerHelper(robot);

    //various init transitions
    Init initializer(transformerHelper, configHelper, all, nullptr);

    int cnt = 0;

    if(loggingActive)
    {
        initializer.activateLogging(logExcludeList);
    }
        
    initializer.executeFunction();

    return 0;

}

void CommonReplay::setLoggingExcludes(const std::vector< std::string >& excludeList)
{
    logExcludeList = excludeList;
}
