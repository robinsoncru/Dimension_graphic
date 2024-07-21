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
    return (int)(f * LONG_WINDOW * 0.5); // Les floats vont de -1 à 1
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

void drawFigures(vecteur v_or, tab_vecteurs vecteurs, SDL_Color color, GraphicCache *cache) {
    // Dessine les vecteurs les uns à la suite des autres à partir de v_or
    for (int i=0; i<vecteurs.nb_vecteur; i++) {
        printVecteur(*vecteurs.tab[i]);
        printVecteur(v_or);
        drawVector(v_or, *vecteurs.tab[i], color, cache);
        add(v_or, *vecteurs.tab[i], v_or);
    }
}

void display(tab_vecteurs vectors, vecteur v_or, GraphicCache *cache)
{
    SDL_Rect screen = {.h = LARG_WINDOW, .w = LONG_WINDOW, .x = 0, .y = 0};
    drawRect(cache->draw, black, screen);
    // Initialise un fond noir

    drawFigures(v_or, vectors, pink, cache);
    v_or.coord[0] = -0.4;
    v_or.coord[1] = 0.4;
    // drawVector(v_or, *vectors.tab[0], pink, cache);
    
    // SDL_Rect r = {.h=40, .w= 30, .x = 0, .y = 0};
    // drawRect(cache->draw, red, r);
    // SDL_Rect r1 = {.h=40, .w= 30, .x = 50, .y = 50};
    // drawRect(cache->draw, pink, r1);
}
