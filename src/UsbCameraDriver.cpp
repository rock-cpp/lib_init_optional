#include "UsbCameraDriver.hpp"
#include <camera_usb/proxies/Task.hpp>

namespace init
{

UsbCameraDriver::UsbCameraDriver(const std::string& taskName): CameraDriver("UsbCameraDriver")
    , cameraTask(DependentTask<camera_usb::proxies::Task>::getInstance(this, taskName))
{
    
}

OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > >& UsbCameraDriver::getFramePort()
{
    return cameraTask.getConcreteProxy()->frame;
}

}