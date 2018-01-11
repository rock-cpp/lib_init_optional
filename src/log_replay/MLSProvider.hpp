#pragma once
#include "../MLSProvider.hpp"
#include <lib_init/log_replay/ReplayPort.hpp>
#include <lib_init/log_replay/ReplayTask.hpp>

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

class MLSPrecalculatedProvider : public init::MLSPrecalculatedProvider
{
    ReplayTask task;
    ReplayPort<envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated>> port;
public:
    MLSPrecalculatedProvider(const std::string& taskName, const std::string& portName);
    virtual bool generateMap();
    virtual OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapPrecalculated > >& getMapPort();
};

}
