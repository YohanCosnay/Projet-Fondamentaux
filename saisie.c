#include <stdio.h>
#include "saisie.h"
#include "config.h"


/*
* Fonction : saisir_releves
* -------------------------
* Demande à l'utilisateur de saisir un nombre de relevés
* puis les températures correspondantes.
*
* Paramètres :
*  - temperatures : tableau contenant les températures saisies
*  - nb_releves   : pointeur vers le nombre de relevés
*/
void action_saisir(float temperatures[], int *nb_releves){

	/* Demande le nombre de relevés tant que la valeur est invalide */
	do
	{
		printf("Nombre de releves (1-%d) : ", MAX_RELEVES);

		/* Vérifie que l'utilisateur saisit bien un entier */
		if (scanf("%d", nb_releves) != 1)
                {
                        printf("Erreur : veuillez saisir un nombre.\n");
                        /* Vide le reste de la ligne */
                        while (getchar() != '\n');
                        continue;
                }

		/* Vérifie que le nombre de relevés est dans l'intervalle autorisé */
		if (*nb_releves < 1 || *nb_releves > MAX_RELEVES)
		{
			printf("Nombres de relevés hors plage (1 - %d)\n", MAX_RELEVES);
		}

	} while (*nb_releves < 1 || *nb_releves > MAX_RELEVES);

	/* Boucle permettant de saisir toutes les températures */
	for( int i=0; i < *nb_releves; i++)
	{

		/* Demande la température correspondant à l'heure i */
		printf("Heure %02d : ",i);

		/* Vérifie que l'utilisateur saisit bien un nombre réel */
		if (scanf("%f", &temperatures[i]) != 1)
    		{
        		printf("Erreur : veuillez saisir un nombre.\n");

        		/* Vide le reste de la ligne */
        		while (getchar() != '\n');
        		continue;
    		}

		/* Redemande la température tant qu'elle est hors de la plage autorisée */
		while(temperatures[i] < TEMP_MIN || temperatures[i] > TEMP_MAX)
		{
                	printf("Valeur hors plage [-50.0 ; 60.0]. Ressaisir : ");

			/* Vérifie que la nouvelle saisie est un nombre réel */
			if (scanf("%f", &temperatures[i]) != 1)
			{
   				printf("Erreur : veuillez saisir un nombre.\n");

				/* Vide le tampon d'entrée */
    				while(getchar() != '\n');
				continue;
			}
	        }
	}
}

/*
* Fonction : afficher_releves
* ---------------------------
* Affiche toutes les températures enregistrées.
*
* Paramètres :
*  - temperatures : tableau contenant les températures.
*  - nb_releves   : nombre de températures à afficher.
*/
void afficher_releves(float temperatures[], int nb_releves)
{
    	printf("\n--- Releves enregistres ---\n");

	/* Parcourt le tableau et affiche chaque température */
    	for(int i = 0; i < nb_releves; i++)
    	{
        	printf("Heure %02d : %.1f °C\n", i, temperatures[i]);
    	}
}
