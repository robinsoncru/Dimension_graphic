#ifndef BOITE_A_OUTILS_VECTEURS
#define BOITE_A_OUTILS_VECTEURS

#include "../structure_espace_vectoriel.h"

bool sameDim(vecteur v1, vecteur v2);
vecteur mallocVect(int dimension);
void freeVecteur(vecteur *v);
void printVecteur(vecteur v);
vecteur createVecteur2D(float x, float y);
// vecteur vecteurMiddleScreen();
void free_tab_vecteurs(tab_vecteurs *vecteurs);
tab_vecteurs create_tab_vecteurs(int nb_vecteurs, int dimension);

#endif