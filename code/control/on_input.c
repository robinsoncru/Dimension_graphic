#include "on_input.h"



void onEscapeUp(GraphicCache *cache)
{
    cache->is_playing = false;
}

void onInput(GraphicCache *cache)
{

    SDL_Event event = cache->event;
    switch (event.type)
    {

    // Select with the mouse
    case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button)
        {
        case SDL_BUTTON_LEFT:
            /* code */
            break;

        case SDL_BUTTON_RIGHT:
            /* code */
            break;

        default:
            assertAndLog(false, "ni bouton sourir gauche ni droite");
            break;
        }
        break;

    case SDL_KEYUP:
        switch (event.key.keysym.sym)
        {
        case SDLK_LEFT:
            // on avance le pion a gauche
            break;

        case SDLK_RIGHT:
            // on avance le pion a droite
            break;

        case SDLK_UP:
            // test des rafles
            break;

        case SDLK_ESCAPE:
            // quits the game
            onEscapeUp(cache);
            break;
        default:
            // assertAndLog(false, "aucune touche reconnue");
            onEscapeUp(cache);
            break;
        }
        break;

    default:
        break;
    }
}
