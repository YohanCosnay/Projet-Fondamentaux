#include <stdio.h>
#include "alerte.h"

#define N 4

int main(void){

    float tab[N] = {2.4, -3.2, 22, 25.2 };

    Config cfg = { .seuil_chaud = 35.0, .seuil_froid = 0.0, .seuil_amplitude = 20.0 }; // Valeur par defaut

    analyser_alertes(tab, N, &cfg);

    return 0;
}