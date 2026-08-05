#ifndef STATS_H
#define STATS_H

float calculer_moyenne(float *tab, int n);
float trouver_minimum(float *tab, int n, int *idx);
float trouver_maximum(float *tab, int n, int *idx);
float calculer_amplitude(float *tab, int n);
void afficher_valeurs_exo2(float moyenne, float min, float max, float amplitude, int idx_min, int idx_max);

#endif