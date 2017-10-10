#pragma once
#include <lib_init/DistanceImageProvider.hpp>
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class DistanceImageProvider : public init::DistanceImageProvider
{
    ReplayTask task;
    ReplayPort<base::samples::DistanceImage> port;
public :
    DistanceImageProvider(const std::string& taskName, const std::string& portName);

    virtual OutputProxyPort< base::samples::DistanceImage >& getDistanceImagePort();    
};

}

