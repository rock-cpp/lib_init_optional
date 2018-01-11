#pragma once

#include <lib_init/Base.hpp>
#include <orocos_cpp/Deployment.hpp>
#include <mars/proxies/TaskForward.hpp>

#include <envire_core/items/SpatioTemporal.hpp>
#include <maps/grid/MLSMap.hpp>

#include <base/Pose.hpp>

#include <lib_init/PositionProvider.hpp>
#include "MLSProvider.hpp"

#include <orocos/mars/sceneType.hpp>
#include <lib_init/DependentTask.hpp>

namespace init
{

class Simulator : public PositionProvider , public MLSProvider
{
protected:
public:
    Simulator(const std::string& simTaskName, const std::shared_ptr< orocos_cpp::Deployment >& simDeployment);
    
    DependentTask<mars::proxies::Task> simulator;

    /** Calling this operator is optional*/
    virtual void setupMLSSimulation(const base::samples::RigidBodyState &robotPose, const envire::core::SpatioTemporal<maps::grid::MLSMapKalman> &mlsKalman);  

    virtual void setupMLSPrecalculatedSimulation(const base::samples::RigidBodyState &robotPose, const envire::core::SpatioTemporal<maps::grid::MLSMapPrecalculated> &mlsPrecalculated);  

    virtual void startSimulation();
    virtual void stopSimulation();  

    virtual bool connect();
    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();

    virtual OutputProxyPort<envire::core::SpatioTemporal< maps::grid::MLSMapKalman> >& getMapPort();
    
    virtual bool generateMap();    

    mars::SerializedScene serializePositions();
    bool loadSerializedPositions(mars::SerializedScene scene);

};
}
