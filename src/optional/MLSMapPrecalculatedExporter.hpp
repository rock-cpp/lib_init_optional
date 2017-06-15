#pragma once


#include "MLSProvider.hpp"
#include <envire_exporters/proxies/MLSMapPrecalculatedExporter.hpp>

namespace init {

class MLSMapPrecalculatedExporter : public MLSProvider
{
    
public:
    MLSMapPrecalculatedExporter(const std::string& taskName);
    virtual bool generateMap();
    virtual OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& getMapPort();

    DependentTask<envire_exporters::proxies::MLSMapPrecalculatedExporter> exporter;
};

}


