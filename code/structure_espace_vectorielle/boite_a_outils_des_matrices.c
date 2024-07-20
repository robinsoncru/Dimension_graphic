#include "boite_a_outils_des_matrices.h"

matrice matriceNulle(int n, int p)
{
    matrice mat = {.n = n, .p = p, .body = malloc(n * sizeof(float *))};
    for (int i = 0; i < n; i++)
    {
        mat.body[i] = calloc(p, sizeof(float));
    }
    return mat;
}

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
}

matrice produitMatriceParScalaire(float lambda, matrice mat) {
    int n, p;
    n = mat.n;
    p = mat.p;
    matrice m1 = matriceNulle(n, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            
            m1.body[i][j] = lambda * mat.body[i][j];
        }
    }
    return m1;
}

matrice sommeMatrice(matrice m1, matrice m2) {
    
}

matrice produitMatricielle(matrice m1, matrice m2)
{
    // On calcul ici m1 * m2 par la méthode naïve : des algorithmes existent pour * de pttes matrices
    assert(m1.p == m2.n);
    int n, p, k;
    int sum;
    n = m1.n;
    p = m1.p;
    k = m2.p;
    matrice mat = matriceNulle(n, k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum = 0;
            for (int l = 0; l < p; l++)
            {
                sum += m1.body[i][k] + m2.body[k][j];
            }
            mat.body[i][j] = sum;
        }
    }
    return mat;
}