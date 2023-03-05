
#include "entry_point.hpp"
#include "core/tobot_application.h"
#include "utilities/logger.hpp"

class Example : public Tobot::Core::TobotApplication
{
public:
    Example()
    {
    
    }

    ~Example()
    {

    }
};

Tobot::Core::TobotApplication * Tobot::Core::CreateApplication()
{
    Tobot::Utilities::Logger::EnableFileOutput();
    LOG_INFO("Hello from Example");
    return new Example();
}