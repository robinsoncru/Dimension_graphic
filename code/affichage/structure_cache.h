#ifndef STRUCTURE_CACHE
#define STRUCTURE_CACHE

#include <SDL2/SDL.h>
#include "../fondamental_structures/basic_headers.h"

#define LG_WINDOW 640
#define FRAME 16


typedef struct
{

    //Frame rate management
    Uint32 last_time;
    Uint32 time_now;

    //window
    SDL_Window* window;
    SDL_Renderer *draw;
    SDL_Event event;
    bool is_playing;


    //error handling
    int statut;

} GraphicCache;

#endif