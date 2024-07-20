#include "draw_geometric.h"




/*







   Geometric functions






*/

void drawPoint(SDL_Renderer *render, SDL_Color color, int x, int y)
{
    // De meme: on fixe la couleur
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
    // On dessine les elm
    SDL_RenderDrawPoint(render, x, y);
}

void drawLine(SDL_Renderer *render, SDL_Color color, int x0, int y0, int x1, int y1)
{
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(render, x0, y0, x1, y1);
}

void drawRect(SDL_Renderer *render, SDL_Color color, const SDL_Rect rect)
{
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(render, &rect);
    // printf("%d %d %d %d", rect.h, rect.w, rect.x, rect.y);
}