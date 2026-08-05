#include <stdio.h>
#include "config.h"
#include "saisie.h"
#include "alerte.h"
#include "stats.h"
#include "Affichage.h"

int main(void) {
    /* Tableau qui stockera les températures et nombre de relevés saisis */
    float temperatures[MAX_RELEVES];

    /* Nombre de relevés saisis */
    int nb_releves = 4;

    /* Appel de la fonction de saisie */
    //saisir_releves(temperatures, &nb_releves);

    //afficher_releves(temperatures, nb_releves);

    //printf("\n");

    // Calcul des stats
    //afficher_valeurs_exo2(temperatures, nb_releves);

    //printf("\n");

    // Affichage des alertes
    Config cfg = {.seuil_chaud = SEUIL_CHAUD, .seuil_froid = SEUIL_FROID, .seuil_amplitude = SEUIL_AMPLITUDE}; // Valeur par defaut
    //analyser_alertes(temperatures, nb_releves, &cfg);

    //printf("\n");
    Menu(temperatures, nb_releves, &cfg);

    return 0;
}
