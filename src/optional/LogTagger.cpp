#include "LogTagger.hpp"
#include <tagger/proxies/Tagger.hpp>

namespace init
{
 
LogTagger::LogTagger(const std::string& name)
    : Base("LogTagger")
    , taggerTask(DependentTask<tagger::proxies::Tagger>::getInstance(this, name))
{
}
    
bool LogTagger::connect()
{
    return init::Base::connect();
}
    
    
}