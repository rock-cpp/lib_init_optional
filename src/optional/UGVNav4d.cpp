#include "UGVNav4d.hpp"


init::UGVNav4d::UGVNav4d(init::MLSProvider& mlsprovider, const std::string& taskName): 
    Base(taskName)
    , mlsprovider(mlsprovider)
    , planner(this, taskName)
{

}

init::UGVNav4d::~UGVNav4d()
{

}


bool init::UGVNav4d::connect()
{
    mlsprovider.getMapPort().connectTo(planner.getConcreteProxy()->map);
    
    return init::Base::connect();
}

