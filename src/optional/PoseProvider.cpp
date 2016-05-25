#include "PoseProvider.hpp"

#include <localization/proxies/PoseProvider.hpp>

namespace init
{

PoseProvider::PoseProvider(const std::string &poseProviderTaskName)
    : Base("PoseProvider"),
      poseProviderTask(this, poseProviderTaskName, "localization::PoseProvider")
{
}

bool PoseProvider::connect()
{
    return init::Base::connect();
}

InputProxyPort< base::samples::RigidBodyState >& PoseProvider::getOdometrySamplesPort()
{
    return poseProviderTask.getConcreteProxy()->odometry_samples;
}

InputProxyPort< graph_slam::PoseProviderUpdate >& PoseProvider::getPoseProviderUpdatePort()
{
    return poseProviderTask.getConcreteProxy()->pose_provider_update;
}

OutputProxyPort< base::samples::RigidBodyState >& PoseProvider::getPoseSamplesPort()
{
    return poseProviderTask.getConcreteProxy()->pose_samples;
}

}