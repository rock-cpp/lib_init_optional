#include "DCDL.hpp"
#include <dcdl/proxies/DifferentialClassifier.hpp>
#include <dcdl/proxies/IMUClassifier.hpp>
#include <dcdl/proxies/TrajectoryClassifier.hpp>
#include <dcdl/proxies/EnsembleClassifier.hpp>
#include <trajectory_follower/proxies/Task.hpp>
#include <ugv_nav4d/proxies/PathPlanner.hpp>

namespace init
{

DCDL::DCDL(const std::string trajClassifierName, const std::string diffClassifierName, const std::string imuClassifierName,
            TrajectoryFollower &trajectoryFollower, PositionProvider &slam, PositionProvider &odometry, IMUDriver &imu)
    : Base("DCDL")
    , trajectoryFollower(trajectoryFollower)
    , slam(slam)
    , odometry(odometry)
    , imu(imu)
    , trajectoryClassifierTask(DependentTask<dcdl::proxies::TrajectoryClassifier>::getInstance(this, trajClassifierName))
    , differentialClassifierTask(DependentTask<dcdl::proxies::DifferentialClassifier>::getInstance(this, diffClassifierName))
    , imuClassifierTask(DependentTask<dcdl::proxies::IMUClassifier>::getInstance(this, imuClassifierName))
{
    registerDependency(trajectoryFollower);
    registerDependency(slam);
    registerDependency(odometry);
    registerDependency(imu);
}


bool DCDL::connect()
{
    trajectoryFollower.trajectoryFollowerTask.getConcreteProxy()->follower_data.connectTo(trajectoryClassifierTask.getConcreteProxy()->follower_data);
    slam.getPositionSamples().connectTo(differentialClassifierTask.getConcreteProxy()->slam_pose);
    odometry.getPositionSamples().connectTo(differentialClassifierTask.getConcreteProxy()->odometry_pose);
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
    , ensembleClassifierTask(DependentTask<dcdl::proxies::EnsembleClassifier>::getInstance(this, taskName))
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
    planner.planner.getConcreteProxy()->traj_with_motions.connectTo(ensembleClassifierTask.getConcreteProxy()->traj_with_motions);
    trajectoryFollower.trajectoryFollowerTask.getConcreteProxy()->current_trajectory.connectTo(ensembleClassifierTask.getConcreteProxy()->cur_trajectory);
    return init::Base::connect();
}

OutputProxyPort< base::commands::Motion2D >& DCDLEnsemble::getCommand2DPort()
{
    return ensembleClassifierTask.getConcreteProxy()->command_out;
}

 
    
}