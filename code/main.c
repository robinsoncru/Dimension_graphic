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

    vecteur v_middle = vecteurNul(2);

    v_middle.coord[0] = 0.5;
    v_middle.coord[1] = 0.5;
    // Start the game
    while (cache->is_playing)
    {
        cache->time_now = SDL_GetTicks();

        if (cache->time_now - cache->last_time > FRAME)
        {
            cache->last_time = cache->time_now;

            // clear the window
            SDL_RenderClear(cache->draw);

            display(v_middle, cache);

            // Rafraichit l'ecran
            SDL_RenderPresent(cache->draw);

            // update the data in the cache

            update(cache);
        }
    }
    freeVecteur(&v_middle);
    return quit(cache);
}