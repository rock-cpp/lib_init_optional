#include "WholeBodyControl.hpp"
#include <wbc/proxies/WbcVelocityTask.hpp>
#include <ctrl_lib/proxies/CartesianPositionController.hpp>
#include <ctrl_lib/proxies/JointPositionController.hpp>
#include <kccd/proxies/SelfCollisionCheck.hpp>
#include <kccd/proxies/SelfCollisionCtrl.hpp>
namespace init 
{
    
WholeBodyControl::WholeBodyControl(const std::string& wbcTaskName, 
                                   const std::string& cartPosCtrlTaskName, 
                                   const std::string& jointPosCtrlTaskName,
                                   const std::string& kccdCheckTaskName,
                                   const std::string& kccdCtrlTaskName) 
    : wbcTask(this, wbcTaskName, "wbc::WbcVelocityTask")
    , cartPosCtrlTask(this, cartPosCtrlTaskName, "ctrl_lib::CartesianPositionController")
    , jointPosCtrlTask(this, jointPosCtrlTaskName, "ctrl_lib::JointPositionController")
    , kccdCheckTask(this, kccdCheckTaskName, "kccd::SelfCollisionCheck")
    , kccdCtrlTask(this, kccdCtrlTaskName, "kccd::SelfCollisionCtrl"){ }

    
bool WholeBodyControl::connect()
{
    jointPosCtrlTask.getConcreteProxy->control_output.connectTo(wbcTask.getConcreteProxy()->ref_joint_control);
    cartPosCtrlTask.getConcreteProxy->control_output.connectTo(wbcTask.getConcreteProxy()->ref_cart_pos_control);
    
    wbcTask.getConcreteProxy()->joint_state_collision.connectTo(kccdCheckTask.getConcreteProxy->joint_state);
    wbcTask.getConcreteProxy()->ctrl_out.connectTo(kccdCtrlTask.getConcreteProxy()->command);
    
    kccdCheckTask.getConcreteProxy()->collision_info.connectTo(kccdCtrlTask.getConcreteProxy()->collision_info);
}

}