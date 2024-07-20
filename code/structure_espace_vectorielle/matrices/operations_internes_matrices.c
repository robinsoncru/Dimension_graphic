#include "operations_internes_matrices.h"

matrice matriceNulle(int n, int p)
{
    matrice mat = {.n = n, .p = p, .body = malloc(n * sizeof(float *))};
    for (int i = 0; i < n; i++)
    {
        mat.body[i] = calloc(p, sizeof(float));
    }
    return mat;
}

void produitMatriceParScalaire(float lambda, matrice mat_start, matrice mat_finish)
{
    assertAndLog(mat_finish.n == mat_start.n && mat_finish.p == mat_start.p, "produitMatriceParScalaire pb dim");
    int n, p;
    n = mat_start.n;
    p = mat_start.p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {

            mat_finish.body[i][j] = lambda * mat_start.body[i][j];
        }
    }
}

void sommeMatrice(matrice m1_start, matrice m2_start, matrice mat_finish)
{
    int n, p;
    n = m1_start.n;
    p = m1_start.p;
    assertAndLog(n == m2_start.n && p == m2_start.p && n == mat_finish.n && p == mat_finish.p,
                 "Matrice pb dimension");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {

            mat_finish.body[i][j] = m1_start.body[i][j] + m2_start.body[i][j];
        }
    }
}
void produitMatricielle(matrice m1_start, matrice m2_start, matrice mat_finish)
{
    // On calcul ici m1 * m2 par la méthode naïve : des algorithmes existent pour * de pttes matrices
    int n, p, k;
    int sum;
    n = m1_start.n;
    p = m1_start.p;
    k = m2_start.p;
    assertAndLog(p == m2_start.n && mat_finish.n == n && mat_finish.p == k, "prodMat pb dim");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum = 0;
            for (int l = 0; l < p; l++)
            {
                sum += m1_start.body[i][k] + m2_start.body[k][j];
            }
            mat_finish.body[i][j] = sum;
        }
    }
}

bool egaliteMatrice(matrice m1, matrice m2)
{
    assertAndLog(m1.n == m2.n && m1.p == m2.p, "Matrice pas de meme dimension");
    int n, p;
    n = m1.n;
    p = m1.p;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {

            if (m1.body[i][j] != m2.body[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// Fonctions qui renvoient une nouvelle matrice, attention à bien la free

matrice giproduitMatriceParScalaire(float lambda, matrice mat_start)
{
    matrice mat_final = matriceNulle(mat_start.n, mat_start.p);
    produitMatriceParScalaire(lambda, mat_start, mat_final);
    return mat_final;
}

matrice gisommeMatrice(matrice m1_start, matrice m2_start)
{
    matrice mat = matriceNulle(m1_start.n, m1_start.p);
    sommeMatrice(m1_start, m2_start, mat);
    return mat;
}

matrice giproduitMatricielle(matrice m1_start, matrice m2_start)
{
    matrice mat = matriceNulle(m1_start.n, m2_start.p);
    produitMatricielle(m1_start, m2_start, mat);
    return mat;
}