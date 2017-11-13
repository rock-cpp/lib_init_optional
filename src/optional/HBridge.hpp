#pragma once

#include <lib_init/Base.hpp>
#include "Canbus.hpp"

#include <hbridge/proxies/CommandWriterForward.hpp>
#include <hbridge/proxies/SensorReaderForward.hpp>
#include <lib_init/JointDriver.hpp>

namespace init 
{
    
class HBridge : public JointDriver
{
    Canbus &canbus;
public:
    HBridge(const std::string& sensorReaderName, const std::string& commandWriterName, Canbus& canbus);
    virtual ~HBridge() {};    
    
    virtual void initProxies();
    virtual bool connect();
    DependentTask<hbridge::proxies::SensorReader> sensorReader;
    DependentTask<hbridge::proxies::CommandWriter> commandWriter;
    
    virtual InputProxyPort< base::commands::Joints >& getCommandPort();
    virtual OutputProxyPort< base::samples::Joints >& getStatusPort();
    
};
    
    
    
}