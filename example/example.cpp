
#include "entry_point.h"
#include "core/tobot_application.h"
#include "utilities/logger.h"
#include "utilities/tobot_asserts.h"

class Example : public Tobot::Core::TobotApplication
{
public:
    Example()
    {
        this->displayWidth = 1200;
        this->displayHeight = 800;
        this->applicationName = "Example";
    }

    ~Example()
    {
        LOG_INFO("Godbye from Example %i", 321);
    }
};

Tobot::Core::TobotApplication * Tobot::Core::CreateApplication()
{
    Tobot::Utilities::Logger::EnableFileOutput();
    LOG_INFO("Hello from Example %i", 123);
    //TOBOT_ASSERT(3 == 1 + 1)
    return new Example();
}