#ifndef ALERTE_H
#define ALERTE_H

#include <stdio.h>

typedef struct {
    float seuil_chaud;      /* alerte CANICULE si température >= seuil */
    float seuil_froid;      /* alerte GEL si température <= seuil      */
    float seuil_amplitude;  /* alerte ECART si amplitude >= seuil      */
} Config;

void analyser_alertes(float *tab, int n, Config *cfg);

#endif