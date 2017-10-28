#include "EncoderIcHaus.hpp"

init::EncoderIcHaus::EncoderIcHaus(const std::string& task_name, init::Canbus& canbus)
    : Base("EncoderIcHaus")
    , canbus(canbus)
    , encoder_task(this, task_name)
{
    canbus.watch(encoder_task.getTaskName(), 0, 0);
    registerDependency(canbus);
}

bool init::EncoderIcHaus::connect()
{
    canbus.getMsgOutPort(encoder_task.getTaskName()).connectTo(encoder_task.getConcreteProxy()->can_in, RTT::ConnPolicy::buffer(200));
    return init::Base::connect();
}

OutputProxyPort< base::samples::Joints >& init::EncoderIcHaus::getStatusSamples()
{
    return encoder_task.getConcreteProxy()->status_samples;
}
