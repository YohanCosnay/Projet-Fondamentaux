#include <stdio.h>
#include "config.h"
#include "temperature_input.h"
#include "alerte.h"
#include "stats.h"

int main(void) {
    /* Tableau qui stockera les températures et nombre de relevés saisis */
    float temperatures[MAX_RELEVES];
    int nb_releves;

    /* Appel de la fonction de saisie et affichage du résumé */
    saisir_releves(temperatures, &nb_releves);
    afficher_releves(temperatures, nb_releves);

    printf("\n");

    // Calcul des stats
    afficher_valeurs_exo2(temperatures, nb_releves);

    printf("\n");

    // Affichage des alertes
    Config cfg = {.seuil_chaud = SEUIL_CHAUD, .seuil_froid = SEUIL_FROID, .seuil_amplitude = SEUIL_AMPLITUDE}; // Valeur par defaut
    analyser_alertes(temperatures, nb_releves, &cfg);

    printf("\n");

    

    return 0;
}
