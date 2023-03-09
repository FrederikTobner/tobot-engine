#include "edl_initializer.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

int Tobot::EDL::EDLInitializerInitialize(uint32_t flags)
{
    uint32_t sdl_core_init_flags;
    if(flags & SDL_CORE_INIT_TIMER)
        sdl_core_init_flags &= SDL_INIT_TIMER;
    if(flags & SDL_CORE_INIT_AUDIO)
        sdl_core_init_flags &= SDL_INIT_AUDIO;     
    if(flags & SDL_CORE_INIT_VIDEO)
        sdl_core_init_flags &= SDL_INIT_VIDEO;
    if(flags & SDL_CORE_INIT_JOYSTICK)
        sdl_core_init_flags &= SDL_INIT_JOYSTICK;
    if(flags & SDL_CORE_INIT_HAPTIC)
        sdl_core_init_flags &= SDL_INIT_HAPTIC;    
    if(flags & SDL_CORE_INIT_GAMECONTROLLER)
        sdl_core_init_flags &= SDL_INIT_GAMECONTROLLER;
    if(flags & SDL_CORE_INIT_EVENTS)
        sdl_core_init_flags &= SDL_INIT_EVENTS;
    
    if(flags & SDL_CORE_INIT_SENSOR)
        sdl_core_init_flags &= SDL_INIT_SENSOR;
    if (SDL_Init(sdl_core_init_flags) < 0)                                           
    {                                                                           
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());    
        return -1;                                                               
    }    
    
    uint32_t sdl_image_init_flags = 0;
    if(flags & SDL_IMAGE_INIT_JPG)
        sdl_image_init_flags |= IMG_INIT_JPG;
    if(flags & SDL_IMAGE_INIT_PNG)
        sdl_image_init_flags |= IMG_INIT_PNG;
    if(flags & SDL_IMAGE_INIT_TIF)
        sdl_image_init_flags |= IMG_INIT_PNG;
    if(flags & SDL_IMAGE_INIT_WEBP)
        sdl_image_init_flags |= IMG_INIT_WEBP;
    if(flags & SDL_IMAGE_INIT_JXL)
        sdl_image_init_flags |= IMG_INIT_JXL;
    if(flags & SDL_IMAGE_INIT_AVIF)
        sdl_image_init_flags |= IMG_INIT_AVIF;
    
    if (IMG_Init(sdl_image_init_flags) < 0)                                           
    {                                                                           
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;                                                               
    }

    if(flags & SDL_TTF_INIT)
    {
        if (TTF_Init()) {
			printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
            IMG_Quit();
            SDL_Quit();
            return -1;
        }
	}

    uint32_t sdl_mixxer_init_flags = 0;
    if(flags & SDL_MIXER_INIT_FLAC)
        sdl_mixxer_init_flags |= MIX_INIT_FLAC;
    if(flags & SDL_MIXER_INIT_MID)
        sdl_mixxer_init_flags |= MIX_INIT_MID;
    if(flags & SDL_MIXER_INIT_MOD)
        sdl_mixxer_init_flags |= MIX_INIT_MOD;
    if(flags & SDL_MIXER_INIT_MP3)
        sdl_mixxer_init_flags |= MIX_INIT_MP3;
    if(flags & SDL_MIXER_INIT_OGG)
        sdl_mixxer_init_flags |= MIX_INIT_OGG;
    if(flags & SDL_MIXER_INIT_OPUS)
        sdl_mixxer_init_flags |= MIX_INIT_OPUS;
    if(flags & SDL_MIXER_INIT_WAVPACK)
        sdl_mixxer_init_flags |= MIX_INIT_WAVPACK;

    if (!Mix_Init(sdl_mixxer_init_flags)) {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        if(flags & SDL_TTF_INIT)
            TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return -1;
    }

    return 0;
}