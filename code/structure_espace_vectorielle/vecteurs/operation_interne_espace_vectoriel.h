#ifndef OPERATION_ESPACE_VECTORIEL
#define OPERATION_ESPACE_VECTORIEL

#include "boite_a_outils_des_vecteurs.h"

vecteur vecteurNul(int dimension);
vecteur add(vecteur v1, vecteur v2);
vecteur extMult(float lambda, vecteur v1);
bool egaliteVect(vecteur v1, vecteur v2);
vecteur appLin(matrice mat, vecteur v);


#endif