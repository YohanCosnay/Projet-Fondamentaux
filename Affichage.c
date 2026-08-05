#include "Affichage.h"
#include "stats.h"

void Menu(float *tab, int n, Config *cfg){

    int choix = 1;

    do{
        printf("   ======== MENU ========\n");
        printf("\t1. Saisir des releves\n");
        printf("\t2. Afficher les statistiques\n");
        printf("\t3. Afficher les alertes\n");
        printf("\t4. Modifier les seuils d'alerte\n");
        printf("\t5. Afficher l'histogramme\n");
        printf("\t0. Quitter\n");
        printf("\tChoix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("===== Saisir releve =====\n");
            saisir_releves(tab, &n);
            break;

        case 2:
            printf("===== Statistiques =====\n");
            afficher_valeurs_exo2(tab, n);
            break;

        case 3:
            analyser_alertes(tab, n, cfg);
            break;

        case 4:
            Modifier_seuils_alerte(cfg);
            break;

        case 5:
            Afficher_Histo(tab, n);
            break;
        
        default:
            break;
        }

    } while(choix != 0);
}

void Afficher_Histo(float *tab, int n){

    printf("===== HISTOGRAMME =====\n");
    float NormalizedValue[n];

    for(int i = 0; i < n; i++){
        NormalizedValue[i] = ((tab[i] - TEMP_MIN) / (TEMP_MAX - TEMP_MIN)) * HISTO_HAUTEUR;
    }

    for(int i = HISTO_HAUTEUR; i > 0; i--){
        for (int j = 0; j < n; j++)
        {
            if(NormalizedValue[j] > i) printf(" * ");
            else printf("   ");
        }
        printf("\n");
    }
    for (int j = 0; j < n; j++)
    {
        printf(" %d ", j);
    }
    
    printf("\n");

}