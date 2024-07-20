#include "handle_cache.h"

GraphicCache *initCache()
{

    // init cache
    GraphicCache *cache = malloc(sizeof(GraphicCache));

    // default values in case of an error in window initialisation
    cache->window = NULL;
    cache->draw = NULL;
    // res -> event has no default value
    cache->is_playing = true;
    // intialisations that might fail

    // frame variables don't need any initial values
    // cache -> time_now is intialized
    // cache -> last_time is initialized

    // error handling in the initilization
    cache->statut = EXIT_FAILURE;

    if (0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
    }
    else if (0 != SDL_CreateWindowAndRenderer(LG_WINDOW, LG_WINDOW, SDL_WINDOW_RESIZABLE, &(cache->window), &(cache->draw)))
    {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
    }
    else
    {
        cache->statut = EXIT_SUCCESS;
    }
    return cache;
}

void freeCache(GraphicCache *cache)
{
    // frame rate management freeing
    // cache->last_time no need to free
    // cache->time_now no need to free

    // text memory freeing
    // cache->txtMessage->display no need to free
    if (NULL != cache->draw)
        SDL_DestroyRenderer(cache->draw);
    if (NULL != cache->window)
        SDL_DestroyWindow(cache->window);

    // error handling freeing
    // cache->statut no need to free

    // time measurement management freeing
    // cache->ticksArray no need to free

    free(cache);
}