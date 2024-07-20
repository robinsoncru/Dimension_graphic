#include "linear_form.h"

float ei_star(int i, vecteur v) {
    assertAndLog(0 <= i && i < v.n, "ei_star indice non valide");
    return v.coord[i];
}