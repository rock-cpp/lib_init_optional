#pragma once

#include <lib_init/JointDriver.hpp>
#include <robot_frames/proxies/TaskForward.hpp>
#include <lib_init/DependentTask.hpp>

namespace init {

class RobotFrames : public Base
{
    std::vector<JointDriver *> joints;
public:
    RobotFrames(const std::string &taskName, const std::vector<JointDriver *> &joints);
    
    virtual bool connect();
    
    DependentTask<robot_frames::proxies::Task> robotFrames;
};

}
