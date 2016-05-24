#pragma once

#include <lib_init/DependentTask.hpp>
#include <lib_init/JointDriver.hpp>
#include "ArmPlanner.hpp" 


namespace manipulator_motion_planner {
    namespace proxies {
        class CartesianSpaceTask;
    }
}

namespace init
{
    
class ArmPlannerCartesianSpace : public ArmPlanner {
    JointDriver &jointDispatcher;
public:
    ArmPlannerCartesianSpace(JointDriver &jointDispatcher, const std::string &armPlannerName);
    virtual bool connect();
    InputProxyPort< ::base::samples::RigidBodyState >& getTargetPort();
    DependentTask< manipulator_motion_planner::proxies::CartesianSpaceTask > cartesianSpacePlanner;
    virtual OutputProxyPort< ::base::JointsTrajectory >& getTrajectoryPort();
    virtual InputProxyPort< base::samples::Pointcloud >& getPointCloudPort();
    virtual InputProxyPort< manipulator_planner_library::ModelObject >& getObjectPort();
    virtual OutputProxyPort< boost::int32_t >& getStatePort();
    virtual InputProxyPort< base::samples::Joints >& getStartPort();
};

}