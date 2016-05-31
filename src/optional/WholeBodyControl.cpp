#include "WholeBodyControl.hpp"
#include <wbc/proxies/WbcVelocityTask.hpp>
#include <ctrl_lib/proxies/CartesianPositionController.hpp>
#include <ctrl_lib/proxies/JointPositionController.hpp>
#include <kccd/proxies/SelfCollisionCheck.hpp>
#include <kccd/proxies/SelfCollisionCtrl.hpp>
#include <waypoint_provider/proxies/JointWaypointProviderTrajectoryInput.hpp>

namespace init 
{
    
WholeBodyControl::WholeBodyControl(TrajectoryGenerationVelocity& trajCtrl,
                                   const std::string& wbcTaskName, 
                                   const std::string& cartPosCtrlTaskName, 
                                   const std::string& jointPosCtrlTaskName,
                                   const std::string& kccdCheckTaskName,
                                   const std::string& kccdCtrlTaskName,
                                   const std::string& waypointProvTaskName) 
    : Base("WholeBodyControl")
    , trajCtrl(trajCtrl)
    , wbcTask(this, wbcTaskName)
    , cartPosCtrlTask(this, cartPosCtrlTaskName)
    , jointPosCtrlTask(this, jointPosCtrlTaskName)
    , kccdCheckTask(this, kccdCheckTaskName)
    , kccdCtrlTask(this, kccdCtrlTaskName)
    , waypointProvTask(this, waypointProvTaskName)
    { 
        
        registerDependency(trajCtrl);
    }

    
bool WholeBodyControl::connect()
{
    waypointProvTask.getConcreteProxy()->current_target.connectTo(jointPosCtrlTask.getConcreteProxy()->setpoint);
    
    wbcTask.getConcreteProxy()->ctrl_out.connectTo(kccdCtrlTask.getConcreteProxy()->command);
    
    kccdCheckTask.getConcreteProxy()->collision_info.connectTo(kccdCtrlTask.getConcreteProxy()->collision_info);
    kccdCtrlTask.getConcreteProxy()->constrained_command_out.connectTo(trajCtrl.getConstrainedVelocityTargetPort());
    
    trajCtrl.getJointStatusPort().connectTo(jointPosCtrlTask.getConcreteProxy()->feedback);
    trajCtrl.getJointStatusPort().connectTo(wbcTask.getConcreteProxy()->joint_state);
    trajCtrl.getJointStatusPort().connectTo(kccdCtrlTask.getConcreteProxy()->joint_state);
    trajCtrl.getJointStatusPort().connectTo(waypointProvTask.getConcreteProxy()->current_position);
    
    return true;
}

bool WholeBodyControl::configure()
{
    
    bool ret = init::Base::configure();
    if(!ret)
        return ret;
    
    wbcTask.getConcreteProxy()->synchronize();
    
    jointPosCtrlTask.getConcreteProxy()->getPort("controlOutput")->connectTo(wbcTask.getConcreteProxy()->getPort("ref_joint_pos_ctrl"));
    cartPosCtrlTask.getConcreteProxy()->getPort("controlOutput")->connectTo(wbcTask.getConcreteProxy()->getPort("ref_cart_pos_ctrl"));
    
    wbcTask.getConcreteProxy()->getPort("joint_state_collision")->connectTo(kccdCheckTask.getConcreteProxy()->getPort("joint_state"));
    wbcTask.getConcreteProxy()->getPort("pose_cart_pos_ctrl")->connectTo(cartPosCtrlTask.getConcreteProxy()->getPort("feedback"));
    
    
    
    
    return ret;
}

InputProxyPort< base::samples::Joints >& WholeBodyControl::getPositionTargetPort()
{
    return jointPosCtrlTask.getConcreteProxy()->setpoint;
}

InputProxyPort< base::JointsTrajectory >& WholeBodyControl::getTrajectoryTargetPort()
{
    return waypointProvTask.getConcreteProxy()->waypoints_in;
}

InputProxyPort< base::samples::RigidBodyState >& WholeBodyControl::getCartPosTargetPort()
{
    return cartPosCtrlTask.getConcreteProxy()->setpoint;
}

OutputProxyPort< base::samples::Joints >& WholeBodyControl::getJointStatusPort()
{
    return trajCtrl.getJointStatusPort();
}

}