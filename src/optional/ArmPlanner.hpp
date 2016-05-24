#pragma once

#include <lib_init/Base.hpp>

#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/RigidBodyState.hpp>
#include <base/JointsTrajectory.hpp>
#include <base/samples/Pointcloud.hpp>
#include <manipulator_planner_library/ModelObject.hpp>
#include <base/commands/Joints.hpp>
#include <rtt/Port.hpp>

namespace manipulator_motion_planner {
    namespace proxies {
        class PlannerTask;
    }
}

namespace init
{

class ArmPlanner : public Base {
public:
    ArmPlanner(const std::string& name) : Base(name) {};
    virtual OutputProxyPort<::base::JointsTrajectory>& getTrajectoryPort() =0;
    virtual InputProxyPort<base::samples::Pointcloud>& getPointCloudPort() =0;
    virtual InputProxyPort<manipulator_planner_library::ModelObject>& getObjectPort() =0;
    virtual OutputProxyPort<boost::int32_t>& getStatePort() =0;
    virtual InputProxyPort<base::samples::Joints>& getStartPort() =0;
};

}