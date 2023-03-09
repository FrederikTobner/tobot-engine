#pragma once

#include <stdint.h>

// Extended Direct Media Layer
namespace Tobot::EDL
{
    typedef enum
    {
        // SDL Core initialization flags
        SDL_CORE_INIT_TIMER             =               0x00000001u,
        SDL_CORE_INIT_AUDIO             =               0x00000002u,
        SDL_CORE_INIT_VIDEO             =               0x00000004u,
        SDL_CORE_INIT_JOYSTICK          =               0x00000008u,
        SDL_CORE_INIT_HAPTIC            =               0x00000010u,
        SDL_CORE_INIT_GAMECONTROLLER    =               0x00000020u,
        SDL_CORE_INIT_EVENTS            =               0x00000040u,
        SDL_CORE_INIT_SENSOR            =               0x00000080u,
        SDL_CORE_INIT_EVERYTHING        =               (SDL_CORE_INIT_TIMER | SDL_CORE_INIT_AUDIO | 
                                                            SDL_CORE_INIT_VIDEO | SDL_CORE_INIT_JOYSTICK | 
                                                            SDL_CORE_INIT_HAPTIC | SDL_CORE_INIT_GAMECONTROLLER | 
                                                            SDL_CORE_INIT_EVENTS | SDL_CORE_INIT_SENSOR),
                                                            
        // SDL Image initialization flags
        SDL_IMAGE_INIT_JPG              =                0x00000100u,
        SDL_IMAGE_INIT_PNG              =                0x00000200u,
        SDL_IMAGE_INIT_TIF              =                0x00000400u,
        SDL_IMAGE_INIT_WEBP             =                0x00000800u,
        SDL_IMAGE_INIT_JXL              =                0x00001000u,
        SDL_IMAGE_INIT_AVIF             =                0x00002000u,
        
        // SDL TTF initialization flags
        SDL_TTF_INIT                    =                0x00004000u,
        
        // SDL Mixer initialization flags
        SDL_MIXER_INIT_FLAC             =                0x00008000u,
        SDL_MIXER_INIT_MOD              =                0x00010000u,
        SDL_MIXER_INIT_MP3              =                0x00020000u,
        SDL_MIXER_INIT_OGG              =                0x00040000u,
        SDL_MIXER_INIT_MID              =                0x00080000u,
        SDL_MIXER_INIT_OPUS             =                0x00100000u,
        SDL_MIXER_INIT_WAVPACK          =                0x00200000
    } SDL_Init_Flags;

    int EDLInitializerInitialize(uint32_t flags);
} // namespace Fars