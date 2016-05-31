#include "HBridge.hpp"


init::HBridge::HBridge(const std::string& sensorReaderName, const std::string& commandWriterName, init::Canbus& canbus)
    : JointDriver("HBridge")
    , canbus(canbus)
    , sensorReader(this, sensorReaderName)
    , commandWriter(this, commandWriterName)
{
    canbus.watch(sensorReader.getTaskName(), 0, 0);
    canbus.watch(commandWriter.getTaskName(), 0, 0);
    registerDependency(canbus);
}

void init::HBridge::initProxies()
{
    init::Base::initProxies();
}


bool init::HBridge::connect()
{   
    sensorReader.getConcreteProxy()->can_out.connectTo(canbus.getMsgInPort(), RTT::ConnPolicy::buffer(200));
    commandWriter.getConcreteProxy()->can_out.connectTo(canbus.getMsgInPort(), RTT::ConnPolicy::buffer(200));
    
    canbus.getMsgOutPort(sensorReader.getTaskName()).connectTo(sensorReader.getConcreteProxy()->can_in, RTT::ConnPolicy::buffer(200));
    canbus.getMsgOutPort(commandWriter.getTaskName()).connectTo(commandWriter.getConcreteProxy()->can_in, RTT::ConnPolicy::buffer(200));
    
    return init::Base::connect();
}

InputProxyPort< base::commands::Joints >& init::HBridge::getCommandPort()
{
    return commandWriter.getConcreteProxy()->command;
}

OutputProxyPort< base::samples::Joints >& init::HBridge::getStatusPort()
{
    return sensorReader.getConcreteProxy()->status_samples;
}


