#ifndef BOITE_A_OUTILS_VECTEURS
#define BOITE_A_OUTILS_VECTEURS

#include "../structure_espace_vectoriel.h"

bool sameDim(vecteur v1, vecteur v2);
vecteur mallocVect(int dimension);
void freeVecteur(vecteur *v);
void printVecteur(vecteur v);
// vecteur vecteurMiddleScreen();

#endif