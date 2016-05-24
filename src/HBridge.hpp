#pragma once

#include "Base.hpp"
#include "Canbus.hpp"

#include <hbridge/proxies/CommandWriter.hpp>
#include <hbridge/proxies/SensorReader.hpp>
#include "JointDriver.hpp"

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