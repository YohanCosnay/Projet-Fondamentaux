#include "stats.h"
#include "config.h"
#include <stdio.h>

// Fonction pour calculer la moyenne des valeurs dans un tableau
float calculer_moyenne(float *tab, int n) {
    float somme = 0.0;

    for (int i = 0; i < n; i++) {
        somme += tab[i];
    }

    return somme / n;
}

// Fonction pour trouver le minimum et son index dans un tableau
float trouver_minimum(float *tab, int n, int *idx) {
    float minimum = tab[0];
    *idx = 0;

    for (int i = 1; i < n; i++) {
        if (tab[i] < minimum) {
            minimum = tab[i];
            *idx = i;
        }
    }

    return minimum;
}


// Fonction pour trouver le maximum et son index dans un tableau
float trouver_maximum(float *tab, int n, int *idx) {
    float maximum = tab[0];
    *idx = 0;

    for (int i = 1; i < n; i++) {
        if (tab[i] > maximum) {
            maximum = tab[i];
            *idx = i;
        }
    }

    return maximum;
}

// Fonction pour calculer l'amplitude (différence entre le maximum et le minimum)
float calculer_amplitude(float *tab, int n) {
    int idx_min;
    int idx_max;

    return trouver_maximum(tab, n, &idx_max) - trouver_minimum(tab, n, &idx_min);
}

// Affichage des valeurs calculées
void afficher_valeurs_exo2(float moyenne, float min, float max, float amplitude, int idx_min, int idx_max) {
    printf("--- Rapport d'analyse ---\n");
    printf("Moyenne     :  %.1f °C\n", moyenne);
    printf("Minimum     :  %.1f °C  (heure %02d)\n", min, idx_min);
    printf("Maximum     :  %.1f °C  (heure %02d)\n", max, idx_max);
    printf("Amplitude   :  %.1f °C\n", amplitude);
}
