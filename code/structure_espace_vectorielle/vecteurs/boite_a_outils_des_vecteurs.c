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

void printVecteur(vecteur v)
{
    for (int i = 0; i < v.n; i++)
    {
        printf("| %f |\n", v.coord[i]);
    }
    printf("\n");
    printf("\n");
    flush();
}

void freeVecteur(vecteur *v)
{
    free(v->coord);
    v->coord = NULL;
    v->n = 0;
}

// vecteur vecteurMiddleScreen() {
//     vecteur v = mallocVect(2);
//     v.coord[0] = 0.5;
//     v.coord[1] = -0.5;
//     return v;
// }