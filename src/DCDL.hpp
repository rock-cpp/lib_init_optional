#pragma once

#include <lib_init/Base.hpp>
#include <dcdl/proxies/DifferentialClassifierForward.hpp>
#include <dcdl/proxies/IMUClassifierForward.hpp>
#include <dcdl/proxies/TrajectoryClassifierForward.hpp>
#include <dcdl/proxies/EnsembleClassifierForward.hpp>
#include <lib_init/IMUDriver.hpp>
#include <lib_init/MotionControl2DProvider.hpp>
#include <lib_init/PositionProvider.hpp>
#include "TrajectoryFollower.hpp"
#include "UGVNav4d.hpp"
#include <lib_init/DependentTask.hpp>
#include <lib_init/log_replay/TrajectoryFollower.hpp>

namespace init
{
 
class DCDL : public Base
{
    
    TrajectoryFollower &trajectoryFollower;
    PositionProvider &slam;
    PositionProvider &odometry;
    IMUDriver &imu;
 
public:
    DCDL(const std::string trajClassifierName, const std::string diffClassifierName, const std::string imuClassifierName,
         TrajectoryFollower &trajectoryFollower, PositionProvider &slam, PositionProvider &odometry, IMUDriver &imu);
    ~DCDL() = default;
    
    virtual bool connect();
    DependentTask<dcdl::proxies::TrajectoryClassifier> trajectoryClassifierTask;
    DependentTask<dcdl::proxies::DifferentialClassifier> differentialClassifierTask;    
    DependentTask<dcdl::proxies::IMUClassifier> imuClassifierTask;
};

class DCDLReplay : public Base
{
    
    log_replay::TrajectoryFollower &trajectoryFollower;
    PositionProvider &slam;
    PositionProvider &odometry;
    IMUDriver &imu;
 
public:
    DCDLReplay(const std::string trajClassifierName, const std::string diffClassifierName, const std::string imuClassifierName,
         log_replay::TrajectoryFollower &trajectoryFollower, PositionProvider &slam, PositionProvider &odometry, IMUDriver &imu);
    ~DCDLReplay() = default;
    
    virtual bool connect();
    DependentTask<dcdl::proxies::TrajectoryClassifier> trajectoryClassifierTask;
    DependentTask<dcdl::proxies::DifferentialClassifier> differentialClassifierTask;    
    DependentTask<dcdl::proxies::IMUClassifier> imuClassifierTask;
};



class DCDLEnsemble : public MotionControl2DProvider
{
    DCDL &dcdl;
    PositionProvider &poseProvider;
    UGVNav4d &planner;
    TrajectoryFollower &trajectoryFollower;
    
public:
    DCDLEnsemble(const std::string taskName, DCDL &dcdl, PositionProvider &poseProvider, UGVNav4d &planner, TrajectoryFollower &trajectoryFollower);
    ~DCDLEnsemble() = default;
    
    virtual bool connect();
    virtual OutputProxyPort<base::commands::Motion2D> &getCommand2DPort();
    DependentTask<dcdl::proxies::EnsembleClassifier> ensembleClassifierTask;
};
    
}