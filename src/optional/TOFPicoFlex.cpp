#include "TOFPicoFlex.hpp"

namespace init 
{

TOFPicoFlex::TOFPicoFlex(const std::string& taskName): 
    DistanceImageProvider("TOFPicoFlex"),
    driver(this, taskName)
{

}

OutputProxyPort< base::samples::DistanceImage >& TOFPicoFlex::getDistanceImagePort()
{
    return driver.getConcreteProxy()->distance_image;
}

};