#pragma once
#include <lib_init/PositionProvider.hpp>
#include <lib_init/DepthMapProvider.hpp>
#include <localization/proxies/VelodyneInMLS.hpp>

namespace init
{

class Localization : public PositionProvider
{
    DepthMapProvider &provider;
public:
    Localization(const std::string taskName, DepthMapProvider &provider);
    
    virtual bool connect();

    
    virtual OutputProxyPort< base::samples::RigidBodyState >& getPositionSamples();
    
    DependentTask<localization::proxies::VelodyneInMLS> localizer;
};

}



