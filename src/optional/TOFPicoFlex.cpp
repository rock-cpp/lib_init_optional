#include "TOFPicoFlex.hpp"

namespace init 
{
    
TOFPicoFlex::TOFPicoFlex(const std::string& taskName): 
    PointCloudProvider("TOFPicoFlex"),
    driver(this, taskName)
{

}

OutputProxyPort< base::samples::Pointcloud >& TOFPicoFlex::getPointCloudPort()
{
    return driver.getConcreteProxy()->pointcloud;
}

    
    
    
    
};
