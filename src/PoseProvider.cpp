#include "PoseProvider.hpp"
#include <simple_pose_integrator/proxies/Task.hpp>

namespace init
{

PoseProvider::PoseProvider(PositionProvider &irregular_pose_provider, const std::string &poseProviderTaskName)
    : Base("PoseProvider")
    , PositionProvider("PoseProvider")
    , irregular_pose_provider(irregular_pose_provider)
    , poseProviderTask(DependentTask< simple_pose_integrator::proxies::Task >::getInstance(this, poseProviderTaskName))
{
    registerDependency(irregular_pose_provider);
}

bool PoseProvider::connect()
{
    irregular_pose_provider.getPositionSamples().connectTo(poseProviderTask.getConcreteProxy()->pose_samples_in);
    return init::Base::connect();
}


OutputProxyPort< base::samples::RigidBodyState >& PoseProvider::getPositionSamples()
{
    return poseProviderTask.getConcreteProxy()->pose_samples;
}

}