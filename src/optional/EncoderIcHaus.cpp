#include "EncoderIcHaus.hpp"

init::EncoderIcHaus::EncoderIcHaus(init::Canbus& canbus, const std::string& task_name)
    : Base("EncoderIcHaus")
    , canbus(canbus)
    , encoder_task(this, task_name)
{
    registerDependency(canbus);
}

bool init::EncoderIcHaus::connect()
{
    //canbus.getMsgOutPort(encoder_task.getTaskName()).connectTo(encoder_task.getConcreteProxy()->can_in, RTT::ConnPolicy::buffer(200));
    return init::Base::connect();
}

OutputProxyPort< base::samples::Joints >& init::EncoderIcHaus::getStatusSamples()
{
    return encoder_task.getConcreteProxy()->status_samples;
}
