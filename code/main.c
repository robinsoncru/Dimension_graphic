#include "main.h"

int quit(GraphicCache *cache)
{
    freeCache(cache);
    SDL_Quit();
    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])
{
    GraphicCache *cache = initCache();

    if (cache->statut != EXIT_SUCCESS)
    {
        return quit(cache);
    }

    // Start the game
    while (cache->is_playing)
    {
        cache->time_now = SDL_GetTicks();

        if (cache->time_now - cache->last_time > FRAME)
        {
            cache->last_time = cache->time_now;

            // clear the window
            SDL_RenderClear(cache->draw);

            update(cache);

            // Rafraichit l'ecran
            SDL_RenderPresent(cache->draw);

            // update the data in the cache
        }
    }
    return quit(cache);
}