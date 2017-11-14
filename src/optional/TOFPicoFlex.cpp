#include "TOFPicoFlex.hpp"
#include <tofcamera_picoflex/proxies/Task.hpp>

namespace init 
{

TOFPicoFlex::TOFPicoFlex(const std::string& taskName): 
    DistanceImageProvider("TOFPicoFlex"),
    driver(DependentTask<tofcamera_picoflex::proxies::Task>::getInstance(this, taskName))
{

}

OutputProxyPort< base::samples::DistanceImage >& TOFPicoFlex::getDistanceImagePort()
{
    return driver.getConcreteProxy()->distance_image;
}

};