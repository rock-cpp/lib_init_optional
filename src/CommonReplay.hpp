#pragma once
#include <vector>
#include "Base.hpp"

class CommonReplay
{
    bool loggingActive;
    std::vector<std::string> logExcludeList;
public:
    CommonReplay(int argc, char **argv);
    
    int runCommon(const smurf::Robot &robot, const std::vector< init::Base* >& toInit);
    

    void setLoggingExcludes(const std::vector<std::string> &excludeList);    
};

