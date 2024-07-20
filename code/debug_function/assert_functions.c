#include "assert_functions.h"



void flush() {
    fflush(stdout);
}

void assertAndLog(bool condition, char *message)
{
    if (!condition)
    {
        printf("\n");
        printf("Erreur : %s", message);
        printf("\n");
        assert(false);
    }
    flush();
}