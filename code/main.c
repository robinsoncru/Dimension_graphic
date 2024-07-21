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

    // vecteur v0 = vecteurNul(2);
    vecteur v_ech1 = createVecteur2D(-0.4, 0.4);
    vecteur cote0 = createVecteur2D(0.8, 0);
    vecteur cote1 = createVecteur2D(0, -0.8);

    tab_vecteurs vectors = create_tab_vecteurs(4, 2);
    vectors.tab[0] = &cote0;
    vectors.tab[1] = &cote1;
    extMult(-1, cote0, *vectors.tab[2]);
    extMult(-1, cote1, *vectors.tab[3]);
    // Start the game
    while (cache->is_playing)
    {
        cache->time_now = SDL_GetTicks();

        if (cache->time_now - cache->last_time > FRAME)
        {
            cache->last_time = cache->time_now;

            // clear the window
            SDL_RenderClear(cache->draw);

            display(vectors, v_ech1, cache);

            // Rafraichit l'ecran
            SDL_RenderPresent(cache->draw);

            // update the data in the cache

            update(cache);
        }
    }
    free_tab_vecteurs(&vectors);
    freeVecteur(&v_ech1);
    return quit(cache);
}