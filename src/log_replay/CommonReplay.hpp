#pragma once
#include <vector>
#include "../Base.hpp"
#include <functional>

namespace smurf
{
    class Robot;
}

namespace log_replay
{

class CommonReplay
{
    bool loggingActive;
    std::vector<std::string> logExcludeList;
    int argc;
    char **argv;
public:
    CommonReplay(int argc, char **argv);
    
    int runCommon(const smurf::Robot &robot, const std::vector< init::Base* >& toInit, std::function<void (void)> threadHook = std::function<void (void)>(), std::function<void (void)> afterInithook = std::function<void (void)>());
    

    void setLoggingExcludes(const std::vector<std::string> &excludeList);    
};

}
