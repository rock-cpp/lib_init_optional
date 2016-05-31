#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/MotionPlannerProvider.hpp>
#include "PoseProvider.hpp"
#include <lib_init/TraversabilityMapProvider.hpp>
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

class MotionPlanner : public MotionPlannerProvider {
    PoseProvider &poseProvider;
    TraversabilityMapProvider &travMapProvider;
    
public:
    DependentTask< motion_planning_libraries::proxies::Task > motionPlanningTask;
    MotionPlanner(PoseProvider &poseProvider, TraversabilityMapProvider &travMapProvider, const std::string &motionPlanningTaskName);
    virtual bool connect();
    virtual OutputProxyPort< std::vector< base::Trajectory > >& getTrajectories();
};

}