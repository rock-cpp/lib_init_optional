#include "MLSProvider.hpp"

namespace log_replay {
    
MLSProvider::MLSProvider(const std::string& taskName, const std::string& portName): 
    init::Base("ReplayMLSProvider"),
    init::MLSProvider("ReplayMLSProvider"),
    task(this, taskName),
    port(task, portName)
{

}

bool MLSProvider::generateMap()
{
    //nothing here
    return false;
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& MLSProvider::getMapPort()
{
    return port.getPort();
}


// MLSMapPrecalculated stuff 

MLSPrecalculatedProvider::MLSPrecalculatedProvider(const std::string& taskName, const std::string& portName)
    : init::Base("ReplayMLSPrecalculatedProvider")
    , init::MLSPrecalculatedProvider("ReplayMLSPrecalculatedProvider")
    , task(this, taskName)
    , port(task, portName)
{

}

bool MLSPrecalculatedProvider::generateMap()
{
    return false;
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapPrecalculated > >& MLSPrecalculatedProvider::getMapPort()
{
    return port.getPort();
}

    
}