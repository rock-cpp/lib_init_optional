#pragma once

#include <lib_init/Base.hpp>

#include <orocos_cpp_base/ProxyPort.hpp>
#include <canbus/proxies/Task.hpp>

namespace canbus {
    class Message;
}


namespace init 
{
    
struct CanbusWatch
{
    std::string name;
    int id;
    int mask;
};
    
class Canbus : public Base
{
    std::map<std::string, OutputProxyPort<::canbus::Message >*> outputs;
    std::vector<CanbusWatch> watches;
public:
    Canbus(const std::string& canbusName);
    virtual ~Canbus() {};
    
    virtual void initProxies();
    virtual bool configure(orocos_cpp::TransformerHelper& trHelper, orocos_cpp::ConfigurationHelper& confHelper);
    
    bool watch(const std::string& name, int id, int mask);
    InputProxyPort<canbus::Message> &getMsgInPort();
    OutputProxyPort<canbus::Message> &getMsgOutPort(const std::string& watchedName);
    DependentTask<canbus::proxies::Task> canbus;
};
    
    
}
