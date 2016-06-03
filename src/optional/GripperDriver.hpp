#pragma once

#include "../Base.hpp"
#include "../JointDriver.hpp"
#include <base/JointsTrajectory.hpp>
#include <spacebot_gripper/Types.hpp>

namespace spacebot_gripper {
    namespace proxies {
        class Task;
    }
}

namespace init
{

class GripperDriver : public Base {
protected:
    JointDriver &jointDriver;
    
public:
    DependentTask< spacebot_gripper::proxies::Task > gripperTask;
    GripperDriver(JointDriver &jd, const std::string &gripperDriverTaskName);
    
    virtual bool connect();
    
    virtual InputProxyPort< spacebot_gripper::Command >& getTrajectoryTargetPort();
    
    virtual OutputProxyPort< base::samples::Joints >& getJointStatusPort();
};

}