#ifndef STATS_H
#define STATS_H

#include "config.h"

float calculer_moyenne(float *tab, int n);
float trouver_minimum(float *tab, int n, int *idx);
float trouver_maximum(float *tab, int n, int *idx);
float calculer_amplitude(float *tab, int n);
void afficher_valeurs_exo2(float *tab, int *n, Config *cfg);

#endif