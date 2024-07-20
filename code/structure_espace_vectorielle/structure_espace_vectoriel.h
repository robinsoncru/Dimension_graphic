#ifndef ESPACE_VECTORIEL
#define ESPACE_VECTORIEL

#include "../debug_function/assert_functions.h"

// On construit un EV de dimension fini n sur le corps des réelles, le neutre du corps est donc 1.

typedef struct
{
    int n;
    int p;
    float **body; /*
          --> mat colonnes
         | 
         v
         n

         l
         i
         g
         n
         e
         s 
    */
} matrice;

typedef struct {
    int n;
    float *coord;
} vecteur;
// Les vecteurs

#endif