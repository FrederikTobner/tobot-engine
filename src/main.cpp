#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "core/farscape_application.h"
#include "./utilities/logger.hpp"

#include "project_config.h"

int main(int argc, char **argv)
{
    Farscape::Core::FarscapeApplication *application = Farscape::Core::FarscapeApplication::getInstance();
     Farscape_Logger::Logger::EnableFileOutput();
    LOG_INFO("%s version %s.%s", PROJECT_NAME, PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR);
    
    application->initialize();
    application->run();
    return 0;
}
