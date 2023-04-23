/**
 * @file sub_system_manager.h
 * @brief Contains the declarations of the functionality that initialize and quit the sub systems of the engine.
 */

#pragma once

#include "pre_compiled_header.h"

namespace Tobot::Core {
/// The bit at the specified position is set to 1. The position is counted from the right to the left and starts at 0.
#define BIT(x) (1 << x)

    /// @brief The flags that can be used to initialize the sub systems of the engine.
    typedef enum {
        // SDL Core initialization flags
        SDL_CORE_INIT_TIMER = BIT(0),
        SDL_CORE_INIT_AUDIO = BIT(1),
        SDL_CORE_INIT_VIDEO = BIT(2),
        SDL_CORE_INIT_JOYSTICK = BIT(3),
        SDL_CORE_INIT_HAPTIC = BIT(4),
        SDL_CORE_INIT_GAMECONTROLLER = BIT(5),
        SDL_CORE_INIT_EVENTS = BIT(6),
        SDL_CORE_INIT_SENSOR = BIT(7),
        SDL_CORE_INIT_EVERYTHING =
            (SDL_CORE_INIT_TIMER | SDL_CORE_INIT_AUDIO | SDL_CORE_INIT_VIDEO | SDL_CORE_INIT_JOYSTICK |
             SDL_CORE_INIT_HAPTIC | SDL_CORE_INIT_GAMECONTROLLER | SDL_CORE_INIT_EVENTS | SDL_CORE_INIT_SENSOR),

        // SDL Image initialization flags
        SDL_IMAGE_INIT_JPG = BIT(8),
        SDL_IMAGE_INIT_PNG = BIT(9),
        SDL_IMAGE_INIT_TIF = BIT(10),
        SDL_IMAGE_INIT_WEBP = BIT(11),
        SDL_IMAGE_INIT_JXL = BIT(12),
        SDL_IMAGE_INIT_AVIF = BIT(13),

        // SDL TTF initialization flags
        SDL_TTF_INIT = BIT(14),

        // SDL Mixer initialization flags
        SDL_MIXER_INIT_FLAC = BIT(15),
        SDL_MIXER_INIT_MOD = BIT(16),
        SDL_MIXER_INIT_MP3 = BIT(17),
        SDL_MIXER_INIT_OGG = BIT(18),
        SDL_MIXER_INIT_MID = BIT(19),
        SDL_MIXER_INIT_OPUS = BIT(20),
        SDL_MIXER_INIT_WAVPACK = BIT(21),

        SDL_SUBSYSTEMS_INIT_EVERYTHING =
            (SDL_CORE_INIT_EVERYTHING | SDL_IMAGE_INIT_JPG | SDL_IMAGE_INIT_PNG | SDL_IMAGE_INIT_TIF |
             SDL_IMAGE_INIT_WEBP | SDL_IMAGE_INIT_JXL | SDL_IMAGE_INIT_AVIF | SDL_TTF_INIT | SDL_MIXER_INIT_FLAC |
             SDL_MIXER_INIT_MOD | SDL_MIXER_INIT_MP3 | SDL_MIXER_INIT_OGG | SDL_MIXER_INIT_MID | SDL_MIXER_INIT_OPUS |
             SDL_MIXER_INIT_WAVPACK)
    } SDL_Init_Flags;

    /// @brief Initializes the sub systems of the engine.
    /// @param flags The flags that specify which sub systems to initialize.
    /// @return 0 if the initialization was successful, -1 otherwise.
    int subSystemsInitialize(uint32_t flags);

    /// @brief Quits the sub systems of the engine.
    void subSystemsQuit();
} // namespace Tobot::Core