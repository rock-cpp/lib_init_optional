#include "GripperDriver.hpp"
#include <spacebot_gripper/proxies/Task.hpp>

namespace init
{
    
GripperDriver::GripperDriver(JointDriver& jd, const std::string& gripperDriverTaskName)
    : Base("GripperDriver")
    , jointDriver(jd)
    , gripperTask(this, gripperDriverTaskName)
{
    registerDependency(jointDriver);
}

bool GripperDriver::connect()
{
    jointDriver.getStatusPort().connectTo(gripperTask.getConcreteProxy()->status_samples);
    gripperTask.getConcreteProxy()->servo_command.connectTo(jointDriver.getCommandPort());
    return Base::connect();
}

InputProxyPort< spacebot_gripper::Command >& GripperDriver::getTrajectoryTargetPort()
{
    return gripperTask.getConcreteProxy()->command;
}

OutputProxyPort< base::samples::Joints >& GripperDriver::getJointStatusPort()
{
    return jointDriver.getStatusPort();
}

}