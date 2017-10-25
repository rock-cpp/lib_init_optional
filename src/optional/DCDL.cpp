#include "DCDL.hpp"

namespace init
{

DCDL::DCDL(const std::string trajClassifierName, const std::string diffClassifierName, const std::string imuClassifierName,
            TrajectoryFollower &trajectoryFollower, PositionProvider &poseProvider, IMUDriver &imu)
    : Base("DCDL")
    , trajectoryFollower(trajectoryFollower)
    , poseProvider(poseProvider)
    , imu(imu)
    , trajectoryClassifierTask(this, trajClassifierName)
    , differentialClassifierTask(this, diffClassifierName)
    , imuClassifierTask(this, imuClassifierName)
{
    registerDependency(trajectoryFollower);
    registerDependency(poseProvider);
    registerDependency(imu);
}


bool DCDL::connect()
{
    trajectoryFollower.trajectoryFollowerTask.getConcreteProxy()->follower_data.connectTo(trajectoryClassifierTask.getConcreteProxy()->follower_data);
    trajectoryFollower.getCommandOut().connectTo(differentialClassifierTask.getConcreteProxy()->motion_cmd);
    poseProvider.getPositionSamples().connectTo(differentialClassifierTask.getConcreteProxy()->robot_pose);
    imu.getSensorSamples().connectTo(imuClassifierTask.getConcreteProxy()->imu_sensors);
    return init::Base::connect();
}

 
 
 
DCDLEnsemble::DCDLEnsemble(const std::string taskName, DCDL& dcdl, PositionProvider &poseProvider, UGVNav4d &planner, TrajectoryFollower &trajectoryFollower)
    : Base("DCDLEnsemble")
    , MotionControl2DProvider("DCDLEnsemble")
    , dcdl(dcdl)
    , poseProvider(poseProvider)
    , planner(planner)
    , trajectoryFollower(trajectoryFollower)
    , ensembleClassifierTask(this, taskName)
{
    registerDependency(dcdl);
    registerDependency(poseProvider);
    registerDependency(planner);
    registerDependency(trajectoryFollower);
}


bool DCDLEnsemble::connect()
{
    dcdl.trajectoryClassifierTask.getConcreteProxy()->fault_trigger.connectTo(ensembleClassifierTask.getConcreteProxy()->fault_receiver);
    dcdl.imuClassifierTask.getConcreteProxy()->fault_trigger.connectTo(ensembleClassifierTask.getConcreteProxy()->fault_receiver);
    dcdl.differentialClassifierTask.getConcreteProxy()->fault_trigger.connectTo(ensembleClassifierTask.getConcreteProxy()->fault_receiver);
    poseProvider.getPositionSamples().connectTo(ensembleClassifierTask.getConcreteProxy()->robot_pose);
    planner.planner.getConcreteProxy()->motionPrims.connectTo(ensembleClassifierTask.getConcreteProxy()->planned_motions);
    planner.planner.getConcreteProxy()->trajectory.connectTo(ensembleClassifierTask.getConcreteProxy()->planned_trajectories);
    trajectoryFollower.trajectoryFollowerTask.getConcreteProxy()->current_trajectory.connectTo(ensembleClassifierTask.getConcreteProxy()->cur_trajectory);
    return init::Base::connect();
}

OutputProxyPort< base::commands::Motion2D >& DCDLEnsemble::getCommand2DPort()
{
    return ensembleClassifierTask.getConcreteProxy()->command_out;
}

 
    
}