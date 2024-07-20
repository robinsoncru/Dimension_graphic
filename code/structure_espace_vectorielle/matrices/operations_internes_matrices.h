#ifndef OPERATION_INTERNE_MATRICE
#define OPERATION_INTERNE_MATRICE

#include "boite_a_outils_des_matrices.h"

matrice matriceNulle(int n, int p);
matrice produitMatriceParScalaire(float lambda, matrice mat);
matrice sommeMatrice(matrice m1, matrice m2);
matrice produitMatricielle(matrice m1, matrice m2);
bool egaliteMatrice(matrice m1, matrice m2);


#endif