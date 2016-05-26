#pragma once

#include "../Base.hpp"
#include "TrajectoryGeneration.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/commands/joints.h>
#include <wbc/Constraint.hpp>
#include <ctrl_lib/ControllerTask.hpp>

namespace wbc {
    namespace proxies {
        class WbcVelocityTask;
    }
}
namespace ctrl_lib {
    namespace proxies {
        class CartesianPositionController;
        class JointPositionController;
    }
}
namespace sensor_processing {
    namespace proxies {
        class SelfCollisionCheck;
        class SelfCollisionCtrl;
    }
}

namespace init {
    class WholeBodyControl : public TrajectoryGeneration {
        TrajectoryControl &trajCtrl;
    public:
        WholeBodyControl(const std::string& wbcTaskName, 
                         const std::string& cartPosCtrlTaskName, 
                         const std::string& jointPosCtrlTaskName,
                         const std::string& kccdCheckTaskName,
                         const std::string& kccdCtrlTaskName);
        
        DependentTask< wbc::proxies::WbcVelocityTask > wbcTask;
        DependantTask< ctrl_lib::proxies::CartesianPositionController > cartPosCtrlTask;
        DependantTask< ctrl_lib::proxies::JointPositionController > jointPosCtrlTask;
        DependantTask< sensor_processing::proxies::SelfCollisionCheck > kccdCheckTask;
        DependentTask< sensor_processing::proxies::SelfCollisionCtrl > kccdCtrlTask;
        
        
        virtual bool connect();
    };
}