#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/Base.hpp>
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/Trajectory.hpp>
#include <envire/core/EventTypes.hpp>

namespace motion_planning_libraries {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class MotionPlanner : public Base {
protected:
    
public:
    DependentTask< motion_planning_libraries::proxies::Task > motionPlanningTask;
    MotionPlanner(const std::string &motionPlanningTaskName);
    virtual bool connect();
    OutputProxyPort< std::vector< base::Trajectory > >& getTrajectoryPort();
    InputProxyPort< base::samples::RigidBodyState >& getStartPoseSamplesPort();
    InputProxyPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& getTraversabilityMapPort();
};

}