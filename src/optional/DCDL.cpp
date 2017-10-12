#include "DCDL.hpp"

namespace init
{

DCDL::DCDL(const std::string trajClassifierName, const std::string diffClassifierName, const std::string imuClassifierName,
            TrajectoryFollower &trajectoryFollower, PoseProvider &poseProvider, IMUDriver &imu)
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

 
 
 
DCDLEnsemble::DCDLEnsemble(const std::string taskName, DCDL& dcdl)
    : Base("DCDLEnsemble")
    , dcdl(dcdl)
    , ensembleClassifierTask(this, taskName)
{
    registerDependency(dcdl);
}


bool DCDLEnsemble::connect()
{
    dcdl.trajectoryClassifierTask.getConcreteProxy()->fault_trigger.connectTo(ensembleClassifierTask.getConcreteProxy()->fault_receiver);
    dcdl.imuClassifierTask.getConcreteProxy()->fault_trigger.connectTo(ensembleClassifierTask.getConcreteProxy()->fault_receiver);
    dcdl.differentialClassifierTask.getConcreteProxy()->fault_trigger.connectTo(ensembleClassifierTask.getConcreteProxy()->fault_receiver);
    return init::Base::connect();
}

 
    
}