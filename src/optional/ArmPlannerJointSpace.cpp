#include "ArmPlannerJointSpace.hpp"

#include <manipulator_motion_planner/proxies/JointSpaceTask.hpp>
#include <manipulator_motion_planner/proxies/PlannerTask.hpp>

namespace init
{
 
ArmPlannerJointSpace::ArmPlannerJointSpace(const std::string& armPlannerName)
    : ArmPlanner("ArmPlannerJointSpace")
    , jointSpacePlanner(this, armPlannerName, "manipulator_motion_planner::JointSpaceTask")
{
}

bool ArmPlannerJointSpace::connect()
{
    return Base::connect();
}

InputProxyPort< base::samples::Joints >& ArmPlannerJointSpace::getTargetPort()
{
    return jointSpacePlanner.getConcreteProxy()->target_joints_angle;
}

OutputProxyPort< ::base::JointsTrajectory >& ArmPlannerJointSpace::getTrajectoryPort()
{
    return jointSpacePlanner.getConcreteProxy()->planned_trajectory;
}

InputProxyPort< base::samples::Pointcloud>& ArmPlannerJointSpace::getPointCloudPort()
{
    return jointSpacePlanner.getConcreteProxy()->environment_in;
}

InputProxyPort< manipulator_planner_library::ModelObject>& ArmPlannerJointSpace::getObjectPort()
{
    return jointSpacePlanner.getConcreteProxy()->known_object;
}

OutputProxyPort< boost::int32_t >& ArmPlannerJointSpace::getStatePort()
{
    return jointSpacePlanner.getConcreteProxy()->state;
}

InputProxyPort< base::samples::Joints >& ArmPlannerJointSpace::getStartPort()
{
    return jointSpacePlanner.getConcreteProxy()->joints_status;
}
    
}