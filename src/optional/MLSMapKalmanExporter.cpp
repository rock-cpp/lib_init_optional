#include "MLSMapKalmanExporter.hpp"

init::MLSMapKalmanExporter::MLSMapKalmanExporter(const std::string& taskName): 
    Base("MLSMapKalmanExporter")
    ,MLSProvider("MLSMapKalmanExporter")
    , exporter(this, taskName)
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
