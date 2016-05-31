#include "TiltScan.hpp"
#include <tilt_scan/proxies/Task.hpp>

namespace init
{

TiltScan::TiltScan(LaserDriver& ld, JointDriver& jd, const std::string& tiltTaskName) 
    : Base("TiltScan")
    , laserDriver(ld)
    , jointDriver(jd)
    , tiltTask(this, tiltTaskName)
{
    registerDependency(laserDriver);
    registerDependency(jointDriver);
}

bool TiltScan::connect()
{
    laserDriver.getLaserReadingsPort().connectTo(tiltTask.getConcreteProxy()->scan_samples, RTT::ConnPolicy::buffer(50));
    jointDriver.getStatusPort().connectTo(tiltTask.getConcreteProxy()->tilt_status_samples, RTT::ConnPolicy::buffer(50));
    tiltTask.getConcreteProxy()->tilt_cmd.connectTo(jointDriver.getCommandPort(), RTT::ConnPolicy::buffer(50));
    return Base::connect();
}

OutputProxyPort< base::samples::Pointcloud > TiltScan::getPointcloud()
{
    return tiltTask.getConcreteProxy()->pointcloud;
}

}
