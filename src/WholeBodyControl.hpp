#pragma once

#include <lib_init/Base.hpp>
#include "TrajectoryGenerationVelocity.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/commands/Joints.hpp>
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
namespace kccd {
    namespace proxies {
        class SelfCollisionCheck;
        class SelfCollisionCtrl;
    }
}
namespace waypoint_provider {
    namespace proxies {
        class JointWaypointProviderTrajectoryInput;
    }
}

namespace init {
    class WholeBodyControl : public Base {
        TrajectoryControl& trajCtrl;
    public:
        WholeBodyControl(TrajectoryControl& trajCtrl,
                         const std::string& wbcTaskName, 
                         const std::string& cartPosCtrlTaskName, 
                         const std::string& jointPosCtrlTaskName,
                         const std::string& kccdCheckTaskName,
                         const std::string& kccdCtrlTaskName,
                         const std::string& waypointProvTaskName);
        
        
        DependentTask< wbc::proxies::WbcVelocityTask > wbcTask;
        DependentTask< ctrl_lib::proxies::CartesianPositionController > cartPosCtrlTask;
        DependentTask< ctrl_lib::proxies::JointPositionController > jointPosCtrlTask;
        DependentTask< kccd::proxies::SelfCollisionCheck > kccdCheckTask;
        DependentTask< kccd::proxies::SelfCollisionCtrl > kccdCtrlTask;
        DependentTask< waypoint_provider::proxies::JointWaypointProviderTrajectoryInput > waypointProvTask;
        
        
        virtual bool connect();
        virtual bool configure();
        
        virtual InputProxyPort< base::samples::RigidBodyState >& getCartPosTargetPort();
        virtual InputProxyPort< base::samples::Joints >& getPositionTargetPort();
        virtual InputProxyPort< base::JointsTrajectory >& getTrajectoryTargetPort();
    
        virtual OutputProxyPort< trajectory_generation::ConstrainedJointsCmd >& getConstrainedCommandOutPort();
        virtual OutputProxyPort< base::samples::Joints > getCommandOutPort();
    };
}