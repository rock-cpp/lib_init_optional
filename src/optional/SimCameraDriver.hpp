#pragma once

#include <lib_init/CameraDriver.hpp>
#include "Simulator.hpp"



namespace init
{

class SimCameraDriver : public CameraDriver
{
public:
    SimCameraDriver(Simulator &sim, const std::string &taskName);

    virtual void initProxies();

    virtual OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > &getFramePort();
    
    DependentTaskBase cameraTask;
protected:
    OutputProxyPort< RTT::extras::ReadOnlyPointer< base::samples::frame::Frame > > *framePort;
};
}
