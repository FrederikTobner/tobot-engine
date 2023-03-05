#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "core/tobot_application.h"

int main(int argc, char **argv)
{
    Tobot::Core::TobotApplication *application = Tobot::Core::TobotApplication::getInstance();
    application->initialize();
    application->run();
    return 0;
}
