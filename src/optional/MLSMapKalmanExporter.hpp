#pragma once

#include <lib_init/MLSProvider.hpp>
#include <envire_exporters/proxies/MLSMapKalmanExporter.hpp>

namespace init {

class MLSMapKalmanExporter : public MLSProvider
{
    
public:
    MLSMapKalmanExporter(const std::string& taskName);
    virtual bool generateMap();
    virtual OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& getMapPort();

    DependentTask<envire_exporters::proxies::MLSMapKalmanExporter> exporter;
};

}
