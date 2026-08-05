#include <stdio.h>
#include "config.h"
#include "temperature_input.h"
#include "alerte.h"
#include "stats.h"

int main(void) {
    /* Tableau qui stockera les températures */
    float temperatures[24] = {2.4, -3.2, 22, 25.2};

    /* Nombre de relevés saisis */
    int nb_releves = 4;
    Config cfg = {.seuil_chaud = 35.0, .seuil_froid = 0.0, .seuil_amplitude = 20.0}; // Valeur par defaut

    /* Appel de la fonction de saisie */
    saisir_releves(temperatures, &nb_releves);

    // Calcul des stats
    int idx_min, idx_max;

    float moyenne = calculer_moyenne(temperatures, nb_releves);
    float min = trouver_minimum(temperatures, nb_releves, &idx_min);
    float max = trouver_maximum(temperatures, nb_releves, &idx_max);
    float amplitude = calculer_amplitude(temperatures, nb_releves);

    // Affichage des stats
    afficher_valeurs_exo2(moyenne, min, max, amplitude, idx_min, idx_max);

    analyser_alertes(temperatures, nb_releves, &cfg);
    return 0;
}
