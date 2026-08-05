#include <stdio.h>
#include "temperature_input.h"

int main(void)
{
    /* Tableau qui stockera les températures */
    float temperatures[MAX_RELEVES];

    /* Nombre de relevés saisis */
    int nb_releves;

    /* Appel de la fonction de saisie */
    saisir_releves(temperatures, &nb_releves);

    return 0;
}
