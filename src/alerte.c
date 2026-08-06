#include "config.h"
#include "alerte.h"
#include "stats.h"


void analyser_alertes(float *tab, int *n, Config *cfg) {

    int IsFine = 1; // Variable booleenne : passe a 0 (faux) si une alerte se declenche

    printf("--- Alertes ---\n");

    for (int i = 0; i < *n; i++) {
        if (tab[i] >= cfg->seuil_chaud) {
            printf("Heure %02d: %.1f °C\t\t[CANICULE]\n", i, tab[i]);
            IsFine = 0;
        }
        else if (tab[i] <= cfg->seuil_froid) {

            printf("Heure %02d: %.1f °C\t\t[GEL]\n", i, tab[i]);
            IsFine = 0;
        }
    }

    float amplitude = calculer_amplitude(tab, *n);
    if (amplitude > cfg->seuil_amplitude) {
        printf("Amplitude: %.1f °C\t\t[ECART]\n", amplitude);
        IsFine = 0;
    }

    if (IsFine) { // Aucune alerte de c'est declenche
        printf("Aucune alerte\n");
    }
}

void Modifier_seuils_alerte(float *tab, int *n, Config *cfg) {
    
    printf("--- Modification des seuils --- \n\n");
    printf("\tNouveau seuil haut : ");
    scanf("%f", &(cfg->seuil_chaud));
    printf("\tNouveau seuil bas : ");
    scanf("%f", &(cfg->seuil_froid));
    printf("\tNouveau seuil d'ecart : ");
    scanf("%f", &(cfg->seuil_amplitude));
}