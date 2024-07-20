#include "update.h"

void update(GraphicCache *cache)
{

    

    // Control pannel
    if (SDL_PollEvent(&(cache->event)) == 1)
    {
        switch (cache->event.type)
        {

        case SDL_QUIT:
            // Exit the game
            cache->is_playing = false;
            break;

        default:
            // called if any input is made
            onInput(cache);
            break;
        }
    }
    else
    {
        // on fait rien pour l'instant
    }
}