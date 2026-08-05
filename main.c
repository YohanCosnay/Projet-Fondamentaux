#include <stdio.h>
#include "temperature_input.h"
#include "alerte.h"

int main(void) {
    /* Tableau qui stockera les températures */
    float temperatures[24] = {2.4, -3.2, 22, 25.2};

    /* Nombre de relevés saisis */
    int nb_releves;
    Config cfg = {.seuil_chaud = 35.0, .seuil_froid = 0.0, .seuil_amplitude = 20.0}; // Valeur par defaut

    /* Appel de la fonction de saisie */
    saisir_releves(temperatures, &nb_releves);

    analyser_alertes(temperatures, nb_releves, &cfg);
    return 0;
}
