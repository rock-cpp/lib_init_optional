#pragma once


#include <lib_init/MLSProvider.hpp>
#include <envire_exporters/proxies/MLSMapPrecalculatedExporterForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init {

class MLSMapPrecalculatedExporter : public MLSPrecalculatedProvider
{
    
public:
    MLSMapPrecalculatedExporter(const std::string& taskName);
    virtual bool generateMap();
    virtual OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapPrecalculated > >& getMapPort();

    DependentTask<envire_exporters::proxies::MLSMapPrecalculatedExporter> exporter;
};

}


