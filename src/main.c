#include <stdio.h>
#include "config.h"
#include "saisie.h"
#include "alerte.h"
#include "stats.h"
#include "affichage.h"

int main(void) {
    /* Tableau qui stockera les températures et nombre de relevés saisis */
    float temperatures[MAX_RELEVES];

    int nb_releves = 0;
    // Affichage des alertes
    Config cfg = {.seuil_chaud = SEUIL_CHAUD, .seuil_froid = SEUIL_FROID, .seuil_amplitude = SEUIL_AMPLITUDE}; // Valeur par defaut

    Menu(temperatures, nb_releves, &cfg);

    return 0;
}
