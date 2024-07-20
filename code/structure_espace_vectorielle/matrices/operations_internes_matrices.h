#ifndef OPERATION_INTERNE_MATRICE
#define OPERATION_INTERNE_MATRICE

#include "boite_a_outils_des_matrices.h"

matrice matriceNulle(int n, int p);
void produitMatriceParScalaire(float lambda, matrice mat_start, matrice mat_finish);
void sommeMatrice(matrice m1_start, matrice m2_start, matrice mat_finish);
void produitMatricielle(matrice m1_start, matrice m2_start, matrice mat_finish);
bool egaliteMatrice(matrice m1, matrice m2);


#endif