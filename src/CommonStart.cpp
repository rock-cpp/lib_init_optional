#include "CommonStart.hpp"

#include <iostream>

#include <state_machine/StateMachine.hpp>
#include <state_machine/Config.hpp>

#include <lib_init/states/Init.hpp>
#include "Container.hpp"

#include <lib_config/Bundle.hpp>

#include <rtt/typekit/RealTimeTypekit.hpp>
#include <rtt/transports/corba/TransportPlugin.hpp>
#include <rtt/transports/corba/TaskContextServer.hpp>
#include <rtt/transports/mqueue/TransportPlugin.hpp>
#include <rtt/OutputPort.hpp>
#include <QApplication>
#include <state_machine/StateMachineWidget.hpp>
#include <smurf/Robot.hpp>
#include <orocos_cpp_base/OrocosHelpers.hpp>
#include <orocos_cpp/PluginHelper.hpp>
#include <orocos_cpp/LoggingHelper.hpp>
#include <logger/Logger.hpp>
#include <rtt/transports/corba/CorbaDispatcher.hpp>
#include "TransformerBroadcaster.hpp"

StartCommon::StartCommon(int argc, char** argv, std::string prefix)
{
    RTT::corba::TaskContextServer::InitOrb(argc, argv);
    
    OrocosHelpers::initClientTask(prefix + "taskManagement");
    
    orocos_cpp::PluginHelper::loadTypekitAndTransports("state_machine_tk");
        
    loggingActive = false;
    simulationActive = false;

    for (int i = 0; i<argc; i++)
    {
        if(strcmp(argv[i], "sim") == 0)
        {
            simulationActive = true;
            std::cout << "Simulation enabled" << std::endl;
        }

        if(strcmp(argv[i], "log") == 0)
        {
            loggingActive = true;
            std::cout << "Logging enabled" << std::endl;
        }
    }


//     if(simulationActive)
//     {
//         std::cout << "Created App" << std::endl;
//         
//         app = new QApplication(argc, argv);
//     
//         widget = new StateMachineWidget();
//         widget->show();
//         widget->resize(800,600);
//     }
    
    //FIXME, we should not need this to be hardcoded here !!!
    RTT::types::TypekitRepository::Import(new RTT::types::RealTimeTypekitPlugin);
    RTT::types::TypekitRepository::Import(new RTT::corba::CorbaLibPlugin);
    RTT::types::TypekitRepository::Import(new RTT::mqueue::MQLibPlugin);

    (state_machine::Config::getConfig(libConfig::Bundle::getInstance().getConfigurationDirectory() + "../taskmanagement.yml"));
}

void StartCommon::setLoggingExcludes(const std::vector< std::string >& excludeList)
{
    logExcludeList = excludeList;
}

int StartCommon::runCommon(state_machine::State *initialState, const std::vector< init::Base* >& toInit)
{
    std::vector< init::Base* > toInitCpy(toInit);
    init::TransformerBroadcaster *broadcaster = new init::TransformerBroadcaster("transformer_broadcaster", *robot);
    toInitCpy.push_back(broadcaster);
    
    init::Container all(toInitCpy); 
    
    //various init transitions
    Init initializer(*transformerHelper, *configHelper, all, initialState);

    state_machine::StateMachine &stateMachine(state_machine::StateMachine::getInstance());

    RTT::TaskContext *clientTask = OrocosHelpers::getClientTask();
    RTT::OutputPort<state_machine::serialization::Event> *eventPort = new RTT::OutputPort<state_machine::serialization::Event>();
    RTT::OutputPort<state_machine::serialization::StateMachine> *dumpPort = new RTT::OutputPort<state_machine::serialization::StateMachine>();
    RTT::OutputPort<std::string> *debugMessages = new RTT::OutputPort<std::string>();
    
    clientTask->addPort("stateMachine_Events", *eventPort);
    clientTask->addPort("stateMachine_Dump", *dumpPort);
    clientTask->addPort("stateMachine_Msg", *debugMessages);

    state_machine::serialization::StateMachine smDump(stateMachine);

    if(loggingActive)
    {
        const std::string loggerName("taskManagement_logger");
        RTT::TaskContext *logger = new logger::Logger(loggerName);
        RTT::corba::TaskContextServer::Create( logger );
        RTT::corba::CorbaDispatcher::Instance( logger->ports(), ORO_SCHED_OTHER, RTT::os::LowestPriority );
        RTT::Activity* activity_Logger = new RTT::Activity(
            ORO_SCHED_OTHER,
            RTT::os::LowestPriority,
            0,
            logger->engine(),
            "taskManagement_logger");

    
        { RTT::os::Thread* thread = dynamic_cast<RTT::os::Thread*>(activity_Logger);
            if (thread)
                thread->setStopTimeout(10);
        }
        logger->setActivity(activity_Logger);

        orocos_cpp::LoggingHelper lHelper;
        lHelper.logAllPorts(clientTask, loggerName, {}, false);
        
    }
    
//     if(simulationActive)
//     {
//         
//         widget->update(smDump);
// //         widget->repaint();
//         app->processEvents();
//     }    

    int cnt = 0;
    
    stateMachine.setExecuteCallback([&](){
        
        if(cnt >= 10)
        {
            cnt = 0;
            
            dumpPort->write(smDump);
        }
        
        cnt++;

        //Events for state_machine visualisation + state_machine
        std::vector<state_machine::serialization::Event> newEvents = stateMachine.getNewEvents();
        for(auto e: newEvents)
        {
            eventPort->write(e);
            
//             if(simulationActive)
//             {
//                 //update widget
//                 widget->update(e);
// //                 widget->repaint();
//             }
        }
//         
//         if(simulationActive)
//         {
//             app->processEvents();
//         }
        
        std::string debugMsgs = stateMachine.getDebugStream().str();
        stateMachine.getDebugStream().str(std::string());

        if(!debugMsgs.empty())
        {
            std::cout << debugMsgs;
            debugMessages->write(debugMsgs);
        }
    }
    );

    if(loggingActive)
    {
        initializer.activateLogging(logExcludeList);
    }
        
    stateMachine.start(&initializer);

    while (!stateMachine.execute())
    {
    }

    return 0;

}

smurf::Robot* StartCommon::getDefaultRobot()
{
    robot = new smurf::Robot;
    std::string smurfPath(libConfig::Bundle::getInstance().getConfigurationDirectory() + state_machine::Config::getConfig().getValue("robotSmurf"));
    std::cout << "Loading Smurf " << smurfPath << std::endl;
    robot->loadFromSmurf(smurfPath);
    
    return robot;
}


void StartCommon::startCommon(smurf::Robot *robot)
{
    this->robot = robot;

    transformerHelper = new orocos_cpp::TransformerHelper(*robot);
    configHelper = new orocos_cpp::ConfigurationHelper();
}



