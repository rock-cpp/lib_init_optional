#pragma once

#include <lib_init/Base.hpp>
#include "ColorizedPointcloud.hpp"

namespace sb_object_detection {
     namespace proxies {
         class Task;
     }
 }

namespace init
{

    class ObjectDetection : public Base {
 protected:
     
     ColorizedPointcloud &colorizedPointcloud; 
     
 public:     
     DependentTask< sb_object_detection::proxies::Task > objectDetectionTask;

     ObjectDetection(ColorizedPointcloud &colorPCl, const std::string &objectDetectionTaskName);
     virtual bool connect();
 };

}