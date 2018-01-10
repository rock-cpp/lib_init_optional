#include "MLSMapKalmanExporter.hpp"
#include <envire_exporters/proxies/MLSMapKalmanExporter.hpp>

init::MLSMapKalmanExporter::MLSMapKalmanExporter(const std::string& taskName): 
    Base("MLSMapKalmanExporter")
    ,MLSProvider("MLSMapKalmanExporter")
    , exporter(DependentTask<envire_exporters::proxies::MLSMapKalmanExporter>::getInstance(this, taskName))
{

}

bool init::MLSMapKalmanExporter::generateMap()
{
    exporter.getConcreteProxy()->writeMap();
    
    return true;
}

OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapKalman > >& init::MLSMapKalmanExporter::getMapPort()
{
    return exporter.getConcreteProxy()->map;
}
