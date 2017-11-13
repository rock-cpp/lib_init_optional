#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/DependentTask.hpp>
#include <tagger/proxies/TaggerForward.hpp>

namespace init
{        
    
class LogTagger : public Base
{
    public:
        LogTagger(const std::string& name);
        ~LogTagger() = default;
        DependentTask<tagger::proxies::Tagger> taggerTask;
        
        virtual bool connect();        
};
}