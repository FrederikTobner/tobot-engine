/**
 * @file sub_system_manager.h
 * @brief Contains the definitions of the functionality that initialize and quit the sub systems of the engine.
 */

#include "sub_system_manager.h"

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "tobot_tooling.h"

using namespace Tobot::Core;
using namespace Tobot::Tooling::Logging;

typedef enum {
    SDL_CORE = BIT(0),
    SDL_IMAGE = BIT(1),
    SDL_MIXER = BIT(2),
    SDL_TTF = BIT(3)
} InitialzedSubSystems;

static uint8_t initialized_sub_systems = 0;

int Tobot::Core::subSystemsInitialize(uint32_t flags) {
    uint32_t sdl_core_init_flags;
    if (flags & SDL_CORE_INIT_TIMER) {
        sdl_core_init_flags |= SDL_INIT_TIMER;
    }
    if (flags & SDL_CORE_INIT_AUDIO) {
        sdl_core_init_flags |= SDL_INIT_AUDIO;
    }
    if (flags & SDL_CORE_INIT_VIDEO) {
        sdl_core_init_flags |= SDL_INIT_VIDEO;
    }
    if (flags & SDL_CORE_INIT_JOYSTICK) {
        sdl_core_init_flags |= SDL_INIT_JOYSTICK;
    }
    if (flags & SDL_CORE_INIT_HAPTIC) {
        sdl_core_init_flags |= SDL_INIT_HAPTIC;
    }
    if (flags & SDL_CORE_INIT_GAMECONTROLLER) {
        sdl_core_init_flags |= SDL_INIT_GAMECONTROLLER;
    }
    if (flags & SDL_CORE_INIT_EVENTS) {
        sdl_core_init_flags |= SDL_INIT_EVENTS;
    }
    if (flags & SDL_CORE_INIT_SENSOR) {
        sdl_core_init_flags |= SDL_INIT_SENSOR;
    }
    if (sdl_core_init_flags) {
        if (SDL_Init(sdl_core_init_flags) < 0) {
            LOG_CRITICAL("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            return -1;
        }
        initialized_sub_systems |= SDL_CORE;
    }

    uint32_t sdl_image_init_flags = 0;
    if (flags & SDL_IMAGE_INIT_JPG) {
        sdl_image_init_flags |= IMG_INIT_JPG;
    }
    if (flags & SDL_IMAGE_INIT_PNG) {
        sdl_image_init_flags |= IMG_INIT_PNG;
    }
    if (flags & SDL_IMAGE_INIT_TIF) {
        sdl_image_init_flags |= IMG_INIT_PNG;
    }
    if (flags & SDL_IMAGE_INIT_WEBP) {
        sdl_image_init_flags |= IMG_INIT_WEBP;
    }
    if (flags & SDL_IMAGE_INIT_JXL) {
        sdl_image_init_flags |= IMG_INIT_JXL;
    }
    if (flags & SDL_IMAGE_INIT_AVIF) {
        sdl_image_init_flags |= IMG_INIT_AVIF;
    }
    if (sdl_image_init_flags) {
        initialized_sub_systems |= SDL_IMAGE;
        if (IMG_Init(sdl_image_init_flags) < 0) {
            LOG_CRITICAL("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
            SDL_Quit();
            return -1;
        }
    }

    if (flags & SDL_TTF_INIT) {
        if (TTF_Init()) {
            LOG_CRITICAL("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            IMG_Quit();
            SDL_Quit();
            return -1;
        }
        initialized_sub_systems |= SDL_TTF;
    }

    uint32_t sdl_mixxer_init_flags = 0;
    if (flags & SDL_MIXER_INIT_FLAC) {
        sdl_mixxer_init_flags |= MIX_INIT_FLAC;
    }
    if (flags & SDL_MIXER_INIT_MID) {
        sdl_mixxer_init_flags |= MIX_INIT_MID;
    }
    if (flags & SDL_MIXER_INIT_MOD) {
        sdl_mixxer_init_flags |= MIX_INIT_MOD;
    }
    if (flags & SDL_MIXER_INIT_MP3) {
        sdl_mixxer_init_flags |= MIX_INIT_MP3;
    }
    if (flags & SDL_MIXER_INIT_OGG) {
        sdl_mixxer_init_flags |= MIX_INIT_OGG;
    }
    if (flags & SDL_MIXER_INIT_OPUS) {
        sdl_mixxer_init_flags |= MIX_INIT_OPUS;
    }
    if (flags & SDL_MIXER_INIT_WAVPACK) {
        sdl_mixxer_init_flags |= MIX_INIT_WAVPACK;
    }
    if (sdl_mixxer_init_flags) {
        if (!Mix_Init(sdl_mixxer_init_flags)) {
            LOG_CRITICAL("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
            if (flags & SDL_TTF_INIT) {
                TTF_Quit();
            }
            IMG_Quit();
            SDL_Quit();
            return -1;
        }
        initialized_sub_systems |= SDL_MIXER;
    }
    return 0;
}

void Tobot::Core::subSystemsQuit() {
    if (initialized_sub_systems & SDL_MIXER) {
        Mix_Quit();
    }
    if (initialized_sub_systems & SDL_TTF) {
        TTF_Quit();
    }
    if (initialized_sub_systems & SDL_IMAGE) {
        IMG_Quit();
    }
    if (initialized_sub_systems & SDL_CORE) {
        SDL_Quit();
    }
}