#include "GenericRawToMotion2D.hpp"

namespace log_replay {

GenericRawToMotion2D::GenericRawToMotion2D(const std::string& taskName, const std::string& portName)
    : init::Base("ReplayGenericRawToMotion2D")
    , init::MotionControl2DProvider("ReplayGenericRawToMotion2D")
    , task(this, taskName)
    , port(task, portName)
{

}

OutputProxyPort< base::commands::Motion2D >& GenericRawToMotion2D::getCommand2DPort()
{
    return port.getPort();
}

    
    
}