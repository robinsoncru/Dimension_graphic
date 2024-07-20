#include "boite_a_outils_des_matrices.h"

void printMatrice(matrice mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        printf(" %d  ", i);
    }
    printf("\n");
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.p; j++)
        {
            float valeur = ((int)mat.body[i][j] * 10) / 10;
            printf(" %f", valeur);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    flush();
}