#include "DistanceImageProvider.hpp"

log_replay::DistanceImageProvider::DistanceImageProvider(const std::string& taskName, const std::string& portName): 
    init::DistanceImageProvider("ReplayDistanceImageProvider"),
    task(this, taskName),
    port(task, portName)
{

}

OutputProxyPort< base::samples::DistanceImage >& log_replay::DistanceImageProvider::getDistanceImagePort()
{
    return port.getPort();
}
