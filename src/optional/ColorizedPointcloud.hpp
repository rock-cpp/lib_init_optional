#pragma once

#include "TiltScan.hpp"
#include <lib_init/CameraDriver.hpp>
#include <base/samples/Pointcloud.hpp>

namespace projection {
     namespace proxies {
         class ColorizePointcloudMultiCam;
     }
}

namespace init
{
    class ColorizedPointcloud : public Base {
    protected:
        TiltScan &tiltScan;
        CameraDriver &camFront;
        CameraDriver &camTower;
        
    public:
        DependentTask< projection::proxies::ColorizePointcloudMultiCam > colorizePointcloudMultiCamTask;
        
        ColorizedPointcloud(TiltScan &tSc, CameraDriver &camFront, CameraDriver &camTower, const std::string &colorizePointcloudMultiCamTaskName);
        virtual bool connect();
        
        OutputProxyPort<base::samples::Pointcloud> getColorizedPointcloud();
        
    };
}