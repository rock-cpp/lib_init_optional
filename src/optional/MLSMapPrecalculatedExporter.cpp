#include "MLSMapPrecalculatedExporter.hpp"

#include "MLSMapKalmanExporter.hpp"

init::MLSMapPrecalculatedExporter::MLSMapPrecalculatedExporter(const std::string& taskName): 
    Base("MLSMapPrecalculatedExporter")
    ,MLSPrecalculatedProvider("MLSMapPrecalculatedExporter")
    , exporter(this, taskName)
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
