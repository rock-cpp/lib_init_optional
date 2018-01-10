#include "GenericRawToMotion2D.hpp"
#include <controldev/proxies/GenericRawToMotion2D.hpp>

namespace init 
{
    
GenericRawToMotion2D::GenericRawToMotion2D(const std::string& taskName)
    : Base(taskName),
      converter(DependentTask<controldev::proxies::GenericRawToMotion2D>::getInstance(this, taskName))
{

}
    
}