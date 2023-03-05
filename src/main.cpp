#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "core/farscape_application.h"

int main(int argc, char **argv)
{
    Farscape::Core::FarscapeApplication *application = Farscape::Core::FarscapeApplication::getInstance();
    application->initialize();
    application->run();
    return 0;
}
