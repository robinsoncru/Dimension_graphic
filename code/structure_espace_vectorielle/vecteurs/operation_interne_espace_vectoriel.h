#ifndef OPERATION_ESPACE_VECTORIEL
#define OPERATION_ESPACE_VECTORIEL

#include "boite_a_outils_des_vecteurs.h"

vecteur vecteurNul(int dimension);
void add(vecteur v1, vecteur v2, vecteur v_finish);
void extMult(float lambda, vecteur v1, vecteur v_finish);
bool egaliteVect(vecteur v1, vecteur v2);
void appLin(matrice mat, vecteur v, vecteur u);
vecteur gadd(vecteur v1, vecteur v2);
vecteur gextMult(float lambda, vecteur v1);
vecteur gappLin(matrice mat, vecteur v_init);


#endif