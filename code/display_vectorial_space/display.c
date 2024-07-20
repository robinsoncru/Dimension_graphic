#include "display.h"

SDL_Color orange = {255, 127, 40, 255};
SDL_Color blue = {0, 0, 255, 255};
SDL_Color red = {255, 0, 0, 255};
SDL_Color green = {0, 255, 0, 255};
SDL_Color white = {255, 255, 255, 255};
SDL_Color black = {0, 0, 0, 255};
SDL_Color gold = {255, 215, 0, 255};
SDL_Color silver = {192, 192, 192, 255};
SDL_Color turquoise = {48, 213, 200};
SDL_Color pink = {255, 20, 147};

int vect_space_to_screen(float f)
{
    return (int)(f * LONG_WINDOW * 0.5); // Les floats vont de 0 à 1
}

void drawVector(vecteur v_or, vecteur v, SDL_Color color, GraphicCache *cache)
{
    assertAndLog(v.n == 2 && v_or.n == 2, "drawVector pb dimension");
    int xmiddle, ymiddle;
    xmiddle = 0.5 * LONG_WINDOW;
    ymiddle = 0.5 * LARG_WINDOW;
    int x = vect_space_to_screen(ei_star(0, v));
    int y = vect_space_to_screen(ei_star(1, v));
    int x0 = vect_space_to_screen(ei_star(0, v_or));
    int y0 = vect_space_to_screen(ei_star(1, v_or));
    // printVecteur(v);
    // printf("%d %d %d %d", x, y, x0, y0);
    drawLine(cache->draw, color, xmiddle + x0, ymiddle - y0, xmiddle + x0 + x, ymiddle - y0  - y);
}

void display(vecteur v, GraphicCache *cache)
{
    SDL_Rect screen = {.h = LARG_WINDOW, .w = LONG_WINDOW, .x = 0, .y = 0};
    drawRect(cache->draw, black, screen);
    // Initialise un fond noir
    vecteur v0 = vecteurNul(2);
    vecteur v_ech1 = createVecteur2D(-0.4, 0.4);
    vecteur v_ech2 = createVecteur2D(0.4, -0.4);
    vecteur v_ech3 = createVecteur2D(-0.4, -0.4);
    vecteur cote0 = createVecteur2D(0.8, 0);
    vecteur cote1 = createVecteur2D(0, 0.8);

    drawVector(v_ech1, cote0, pink, cache);
    drawVector(v_ech2, cote1, pink, cache);
    drawVector(v_ech3, cote0, pink, cache);
    drawVector(v_ech3, cote1, pink, cache);

    freeVecteur(&v0);
    freeVecteur(&v_ech1);
    freeVecteur(&v_ech2);
    freeVecteur(&v_ech3);
    freeVecteur(&cote0);
    freeVecteur(&cote1);
    // SDL_Rect r = {.h=40, .w= 30, .x = 0, .y = 0};
    // drawRect(cache->draw, red, r);
    // SDL_Rect r1 = {.h=40, .w= 30, .x = 50, .y = 50};
    // drawRect(cache->draw, pink, r1);
}
