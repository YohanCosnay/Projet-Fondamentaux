#include "affichage.h"
#include "stats.h"

void Menu(float *tab, int n, Config *cfg){

    /************************************/
    /*           Menu principal         */
    /************************************/
    /*                                  */
    /*  Gere l'interface utilisateur    */
    /*  Appel les fonction appropriees  */
    /*  aux demandes de l'utilisateur   */
    /*                                  */
    /************************************/
    int choix = 0;

    do{
        printf("\t  =========== MENU ===========\n");
        printf("\t| 1. Saisir des releves\n");
        printf("\t| 2. Afficher les statistiques\n");
        printf("\t| 3. Afficher les alertes\n");
        printf("\t| 4. Modifier les seuils d'alerte\n");
        printf("\t| 5. Afficher l'histogramme\n");
        printf("\t| 0. Quitter\n");
        printf("\t  ============================\n");

        do {
            printf("Votre choix : ");

            // Vérifie si l'entrée est un nombre entier
            if (scanf("%d", &choix) != 1) {
                printf("Erreur : Entree invalide. Réessayez.\n");
                // Nettoie le buffer pour éviter une boucle infinie
                while (getchar() != '\n');
                continue;
            }

        } while (choix < 0 || choix > 5); // Répète tant que le nombre n'est pas valide

        switch (choix)
        {
        case 1:
            printf("===== Saisir releve =====\n");
            action_saisir(tab, &n);
            afficher_releves(tab, n);
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

    /************************************/
    /*           Histogramme            */
    /************************************/
    /*                                  */
    /*  Genere l'histogramme ASCII      */
    /*                                  */
    /************************************/

    printf("===== HISTOGRAMME =====\n");
    float NormalizedValue[n];

    // Remplis un tableau contenant les valeurs de temperature, normaliser entre à et 5
    for(int i = 0; i < n; i++){
        NormalizedValue[i] = ((tab[i] - TEMP_MIN) / (TEMP_MAX - TEMP_MIN)) * HISTO_HAUTEUR;
    }

    // Ecrit le tableau en partant du haut
    for(int i = HISTO_HAUTEUR; i > 0; i--){
        for (int j = 0; j < n; j++)
        {
            if(NormalizedValue[j] > i) printf("  * ");
            else printf("    ");
        }
        printf("\n");
    }

    // Trace le separateur
    for (int j = 0; j < n; j++)
    {
        printf("----");
    }
    
    printf("\n");

    // Indique les heure de chacuns des points
    for (int j = 0; j < n; j++)
    {
        printf(" %2d ", j);
    }
    
    printf("\n");

}
