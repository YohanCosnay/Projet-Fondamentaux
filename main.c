#include <stdio.h>
#include "config.h"
#include "temperature_input.h"
#include "alerte.h"
#include "stats.h"

int main(void) {
    /* Tableau qui stockera les températures */
    float temperatures[MAX_RELEVES];

    /* Nombre de relevés saisis */
    int nb_releves;

    /* Appel de la fonction de saisie */
    saisir_releves(temperatures, &nb_releves);

    // Calcul des stats
    afficher_valeurs_exo2(temperatures, nb_releves);

    Config cfg = {.seuil_chaud = 35.0, .seuil_froid = 0.0, .seuil_amplitude = 20.0}; // Valeur par defaut
    analyser_alertes(temperatures, nb_releves, &cfg);
    return 0;
}
