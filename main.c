#include <stdio.h>
<<<<<<< HEAD
#include "temperature_input.h"

int main(void)
{
    /* Tableau qui stockera les températures */
    float temperatures[MAX_RELEVES];

    /* Nombre de relevés saisis */
    int nb_releves;

    /* Appel de la fonction de saisie */
    saisir_releves(temperatures, &nb_releves);

=======
#include "alerte.h"

#define N 4

int main(void){

    float tab[N] = {2.4, -3.2, 22, 25.2 };

    Config cfg = { .seuil_chaud = 35.0, .seuil_froid = 0.0, .seuil_amplitude = 20.0 }; // Valeur par defaut

    analyser_alertes(tab, N, &cfg);

>>>>>>> 73788ee12c714b4eeb6e35464ad6eb3b0745f482
    return 0;
}
