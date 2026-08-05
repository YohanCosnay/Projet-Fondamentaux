#include "alerte.h"
#include "stats.h"


void analyser_alertes(float *tab, int n, Config *cfg){

    int IsFine = 1;

    printf("===== Rapport d'alerte =====\n");

    for(int i = 0; i < n; i++){
        if(tab[i] >= cfg->seuil_chaud){
            printf("\t[CANICULE]\n");
            IsFine = 0;
        }
        else if(tab[i] <= cfg->seuil_froid){

            printf("\t[GEL]\n");
            IsFine = 0;
        }
    }

    if(calculer_amplitude(tab, n) > cfg->seuil_amplitude){
        printf("\t[ECART]\n");
        IsFine = 0;
    }

    if(IsFine){
        printf("Aucune alerte\n");
    }

    printf("===== Fin du rapport =====\n\n");
}

void Modifier_seuils_alerte(Config *cfg){

    printf("===== Modification des seuils =====\n\n");
    printf("\tNouveau seuil haut : ");
    scanf("%f", cfg->seuil_chaud);
    printf("\tNouveau seuil bas : ");
    scanf("%f", cfg->seuil_froid);
    printf("\tNouveau seuil d'ecart : ");
    scanf("%f", cfg->seuil_amplitude);
}