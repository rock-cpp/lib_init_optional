#pragma once

#include <lib_init/DependentTask.hpp>
#include "ArmPlanner.hpp"

namespace manipulator_motion_planner {
    namespace proxies {
        class JointSpaceTask;
    }
}

namespace init
{
    
class ArmPlannerJointSpace : public ArmPlanner {
public:
    ArmPlannerJointSpace(const std::string &armPlannerName);
    virtual bool connect();
    InputProxyPort< base::samples::Joints >& getTargetPort();
    DependentTask< manipulator_motion_planner::proxies::JointSpaceTask > jointSpacePlanner;
    virtual OutputProxyPort< ::base::JointsTrajectory >& getTrajectoryPort();
    virtual InputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
    virtual InputProxyPort< manipulator_planner_library::ModelObject >& getObjectPort();
    virtual OutputProxyPort< boost::int32_t >& getStatePort();
    virtual InputProxyPort< base::samples::Joints >& getStartPort();
};

}