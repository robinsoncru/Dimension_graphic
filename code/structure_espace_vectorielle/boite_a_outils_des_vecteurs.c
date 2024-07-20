#include "boite_a_outils_des_vecteurs.h"


bool sameDim(vecteur v1, vecteur v2)
{
    return v1.n == v2.n;
}

vecteur mallocVect(int dimension)
{

    vecteur v = {.n = dimension, .coord = malloc(dimension * sizeof(float))};
    return v;
}



void freeVecteur(vecteur *v) {
    free(v->coord);
    v->coord = NULL;
    v->n = 0;
}