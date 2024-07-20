#include "operation_interne_espace_vectoriel.h"

/* Ces opérations sont contenues à l'intérieur de l'espace vectorielle, elles ne doivent donc être utilisées
qu'à l'initialisation */

vecteur vecteurNul(int dimension)
{
    vecteur v = {.n = dimension, .coord = calloc(dimension, sizeof(float))};
    return v;
}

void add(vecteur v1, vecteur v2, vecteur v_finish)
{
    assertAndLog(sameDim(v1, v2) && sameDim(v1, v_finish), "add : vecteurs pas meme dimension");
    int n = v1.n;
    for (int i = 0; i < n; i++)
    {
        v_finish.coord[i] = v1.coord[i] + v2.coord[i];
    }
}

void extMult(float lambda, vecteur v1, vecteur v_finish)
{
    assertAndLog(sameDim(v1, v_finish), "extMult : pb dim");
    int n = v1.n;
    for (int i = 0; i < n; i++)
    {
        v_finish.coord[i] = lambda * v1.coord[i];
    }
}

bool egaliteVect(vecteur v1, vecteur v2)
{
    assertAndLog(sameDim(v1, v2), "egaliteVect : vecteur pas meme dimension");
    int n = v1.n;
    for (int i = 0; i < n; i++)
    {
        if (v1.coord[i] != v2.coord[i])
        {
            return false;
        }
    }
    return true;
}

void appLin(matrice mat, vecteur v, vecteur u)
{
    assertAndLog(mat.p == v.n && u.n == mat.n, "appLin dim diff");
    int s;
    for (int i = 0; i < mat.n; i++)
    {
        s = 0;
        for (int j = 0; j < v.n; j++)
        {
            s += mat.body[i][j] * v.coord[j];
        }

        u.coord[i] = s;
    }
}