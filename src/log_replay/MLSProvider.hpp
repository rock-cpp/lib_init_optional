#pragma once
#include <lib_init/MLSProvider.hpp>
#include "ReplayPort.hpp"
#include "ReplayTask.hpp"

namespace log_replay
{

class MLSProvider : public init::MLSProvider
{
    ReplayTask task;
    ReplayPort<envire::core::SpatioTemporal< maps::grid::MLSMapKalman >> port;
public :
    MLSProvider(const std::string& taskName, const std::string& portName);
    virtual bool generateMap();
    virtual OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& getMapPort();
};

}
