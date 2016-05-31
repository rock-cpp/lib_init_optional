#include "ColorizedPointcloud.hpp"
#include <projection/proxies/ColorizePointcloudMultiCam.hpp>

namespace init 
{
    
ColorizedPointcloud::ColorizedPointcloud(TiltScan &tSc, CameraDriver &camFront, CameraDriver &camTower, const std::string &colorizePointcloudMultiCamTaskName)
    : Base("ColorizedPointcloud")
    , tiltScan(tSc)
    , camFront(camFront)
    , camTower(camTower)
    , colorizePointcloudMultiCamTask(this, colorizePointcloudMultiCamTaskName)
{
    registerDependency(tiltScan);
    registerDependency(camFront);
    registerDependency(camTower);
}
 
bool ColorizedPointcloud::connect()
{
    tiltScan.getPointcloud().connectTo(colorizePointcloudMultiCamTask.getConcreteProxy()->points, RTT::ConnPolicy::buffer(5));    
    camFront.getFramePort().connectTo(colorizePointcloudMultiCamTask.getConcreteProxy()->camera1, RTT::ConnPolicy::buffer(5));
    camTower.getFramePort().connectTo(colorizePointcloudMultiCamTask.getConcreteProxy()->camera2, RTT::ConnPolicy::buffer(5));
    return init::Base::connect();
}

OutputProxyPort< base::samples::Pointcloud > ColorizedPointcloud::getColorizedPointcloud()
{
    return colorizePointcloudMultiCamTask.getConcreteProxy()->colored_points;
}

 
}