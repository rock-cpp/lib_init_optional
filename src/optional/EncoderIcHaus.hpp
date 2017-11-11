#pragma once

#include "Canbus.hpp"
#include <lib_init/Base.hpp>
#include <encoder_ichaus/proxies/Task.hpp>
#include <lib_init/DependentTask.hpp>

namespace init 
{

    class EncoderIcHaus : public Base
    {
    protected:
        Canbus &canbus;

    public:
        EncoderIcHaus(const std::string& task_name, init::Canbus& canbus);
        virtual bool connect();
        virtual OutputProxyPort< base::samples::Joints >& getStatusSamples();

        DependentTask<encoder_ichaus::proxies::Task> encoder_task;

    };
}
