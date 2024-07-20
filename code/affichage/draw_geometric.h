#ifndef DRAW_GEOMETRIC
#define DRAW_GEOMETRIC

#include "handle_cache.h"

void drawLine(SDL_Renderer *render, SDL_Color color, int x0, int y0, int x1, int y1);
void drawRect(SDL_Renderer *render, SDL_Color color, const SDL_Rect rect);
void drawPoint(SDL_Renderer *render, SDL_Color color, int x, int y);

#endif