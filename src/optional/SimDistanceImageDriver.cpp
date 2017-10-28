#include "SimDistanceImageDriver.hpp"

#include "Simulator.hpp"


namespace init
{

SimDistanceImageDriver::SimDistanceImageDriver(Simulator& sim, const std::string& distanceImageTaskName) : DistanceImageProvider("SimDistanceImageDriver"),
        distanceImageTask(this, distanceImageTaskName)
{
    distanceImageTask.setDeployment(sim.simulator.getDeployment());
    registerDependency(sim);
}

OutputProxyPort< base::samples::DistanceImage >& SimDistanceImageDriver::getDistanceImagePort()
{
    return distanceImageTask.getConcreteProxy()->distance_image;
}



} // namespace init
