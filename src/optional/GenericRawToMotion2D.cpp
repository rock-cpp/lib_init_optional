#include "GenericRawToMotion2D.hpp"

namespace init 
{
    
GenericRawToMotion2D::GenericRawToMotion2D(const std::string& taskName)
    : Base(taskName),
      converter(this, taskName)
{

}
    
}