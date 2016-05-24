#pragma once

#include <functional>
#include <state_machine/State.hpp>

class QApplication;
class StateMachineWidget;

namespace init {
    class Base;
}

namespace orocos_cpp
{
    class TransformerHelper;
    class ConfigurationHelper;
}

namespace smurf 
{
    class Robot;
}

class StartCommon
{
    bool loggingActive;
    bool simulationActive;
    QApplication *app;
    StateMachineWidget *widget;

    void startCommon();
    int runCommon(state_machine::State *initialState, const std::vector< init::Base* >& toInit);
    
    orocos_cpp::TransformerHelper *transformerHelper;
    orocos_cpp::ConfigurationHelper *configHelper;
    smurf::Robot *robot;
    
public:
    StartCommon(int argc, char **argv);

    
    template< class Startup>
    int run(const std::function<state_machine::State *(Startup &start, std::vector<init::Base *> &toInit)> &ownstuff)
    {
        startCommon();
        
        Startup start(simulationActive);
        std::vector<init::Base *> toInit;
        
//         startUp = &start;
        
        state_machine::State *initialState = ownstuff(start, toInit);
        
        return runCommon(initialState, toInit);
    }
};
