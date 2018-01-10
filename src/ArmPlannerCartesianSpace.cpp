#include "ArmPlannerCartesianSpace.hpp"

#include <manipulator_motion_planner/proxies/CartesianSpaceTask.hpp>
#include <manipulator_motion_planner/proxies/PlannerTask.hpp>

namespace init
{
 
ArmPlannerCartesianSpace::ArmPlannerCartesianSpace(init::JointDriver& jointDispatcher, const std::string& armPlannerName)
    : ArmPlanner("ArmPlannerCartesianSpace")
    , jointDispatcher(jointDispatcher)
    , cartesianSpacePlanner(this, armPlannerName)
{
    registerDependency(jointDispatcher);
}

bool ArmPlannerCartesianSpace::connect()
{
    jointDispatcher.getStatusPort().connectTo(cartesianSpacePlanner.getConcreteProxy()->joints_status);
    
    return Base::connect();
}

InputProxyPort< ::base::samples::RigidBodyState >& ArmPlannerCartesianSpace::getTargetPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->target_pose;
}

OutputProxyPort< ::base::JointsTrajectory >& ArmPlannerCartesianSpace::getTrajectoryPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->planned_trajectory;
}

InputProxyPort< base::samples::Pointcloud>& ArmPlannerCartesianSpace::getPointCloudPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->environment_in;
}

InputProxyPort< manipulator_planner_library::ModelObject>& ArmPlannerCartesianSpace::getObjectPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->known_object;
}

OutputProxyPort< boost::int32_t >& ArmPlannerCartesianSpace::getStatePort()
{
    return cartesianSpacePlanner.getConcreteProxy()->state;
}

InputProxyPort< base::samples::Joints >& ArmPlannerCartesianSpace::getStartPort()
{
    return cartesianSpacePlanner.getConcreteProxy()->joints_status;
}

}