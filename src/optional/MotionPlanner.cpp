#include "MotionPlanner.hpp"

#include <motion_planning_libraries/proxies/Task.hpp>

namespace init
{

MotionPlanner::MotionPlanner(const std::string &motionPlanningTaskName)
    : Base("MotionPlanner"),
      motionPlanningTask(this, motionPlanningTaskName, "motion_planning_libraries::Task")
{
}

bool MotionPlanner::connect()
{
    return init::Base::connect();
}

InputProxyPort< base::samples::RigidBodyState >& MotionPlanner::getStartPoseSamplesPort()
{
    return motionPlanningTask.getConcreteProxy()->start_pose_samples;
}

OutputProxyPort< std::vector< base::Trajectory > >& MotionPlanner::getTrajectoryPort()
{
    return motionPlanningTask.getConcreteProxy()->trajectory;
}

InputProxyPort< RTT::extras::ReadOnlyPointer< std::vector< envire::BinaryEvent > > >& MotionPlanner::getTraversabilityMapPort()
{
    return motionPlanningTask.getConcreteProxy()->traversability_map;
}

}