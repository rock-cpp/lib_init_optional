#include "MLSMapPrecalculatedExporter.hpp"

#include "MLSMapKalmanExporter.hpp"
#include <envire_exporters/proxies/MLSMapPrecalculatedExporter.hpp>

init::MLSMapPrecalculatedExporter::MLSMapPrecalculatedExporter(const std::string& taskName): 
    Base("MLSMapPrecalculatedExporter")
    ,MLSPrecalculatedProvider("MLSMapPrecalculatedExporter")
    , exporter(DependentTask<envire_exporters::proxies::MLSMapPrecalculatedExporter>::getInstance(this, taskName))
{

}

bool init::MLSMapPrecalculatedExporter::generateMap()
{
    exporter.getConcreteProxy()->writeMap();
    
    return true;
}


OutputProxyPort< envire::core::SpatioTemporal< maps::grid::MLSMapPrecalculated > >& init::MLSMapPrecalculatedExporter::getMapPort()
{
    return exporter.getConcreteProxy()->map;
}
