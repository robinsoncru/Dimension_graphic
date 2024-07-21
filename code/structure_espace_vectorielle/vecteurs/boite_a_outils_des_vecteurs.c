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

vecteur createVecteur2D(float x, float y)
{
    vecteur u = mallocVect(2);
    u.coord[0] = x;
    u.coord[1] = y;
    return u;
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

void free_tab_vecteurs(tab_vecteurs *vecteurs)
{
    for (int i = 0; i < vecteurs->nb_vecteur; i++)
    {
        freeVecteur(vecteurs->tab[i]);
    }
    free(vecteurs->tab);
    vecteurs->nb_vecteur = 0;
}

tab_vecteurs create_tab_vecteurs(int nb_vecteurs, int dimension)
{
    // Renvoie une liste de pointeurs de vecteurs vide, deja dimensionné
    tab_vecteurs vectors = {.nb_vecteur = nb_vecteurs, .tab = malloc(nb_vecteurs * sizeof(vecteur*))};
    for (int i = 0; i < nb_vecteurs; i++)
    {
        vecteur v = {.n = dimension, .coord = NULL};
        vectors.tab[i] = &v;
    }
    return vectors;
}

// vecteur vecteurMiddleScreen() {
//     vecteur v = mallocVect(2);
//     v.coord[0] = 0.5;
//     v.coord[1] = -0.5;
//     return v;
// }