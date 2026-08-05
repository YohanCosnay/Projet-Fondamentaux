#include <stdio.h>
#include "config.h"
#include "temperature_input.h"


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
void saisir_releves(float temperatures[], int *nb_releves) {

	/* Demande le nombre de relevés à l'utilisateur tant que le nombre n'est
	   pas compris entre 1 et le nombre max de relevés (24)*/
	do {
		printf("Nombre de releves (1-%d) : ", MAX_RELEVES);

		if (scanf("%d", nb_releves) != 1) {
			printf("Erreur : veuillez saisir un nombre.\n");
			/* Vide le reste de la ligne */
			while (getchar() != '\n');
			continue;
		}

		if (*nb_releves < 1 || *nb_releves > MAX_RELEVES) {
			printf("Nombres de relevés hors plage (1 - %d)\n", MAX_RELEVES);
		}

	} while (*nb_releves < 1 || *nb_releves > MAX_RELEVES);

	printf("\n");

	/* Saisie de chaque température */
	for (int i = 0; i < *nb_releves; i++) {
		/* Température à l'heure i */
		printf("Heure %02d : ",i);

		if (scanf("%f", &temperatures[i]) != 1) {
			printf("Erreur : veuillez saisir un nombre.\n");
			/* Vide le reste de la ligne */
			while (getchar() != '\n');
			continue;
		}

		/* Vérification de la température */
		while (temperatures[i] < TEMP_MIN || temperatures[i] > TEMP_MAX) {
			printf("Valeur hors plage [-50.0 ; 60.0]. Ressaisir : ");

			if (scanf("%f", &temperatures[i]) != 1) {
   				printf("Erreur : veuillez saisir un nombre.\n");
    				while (getchar() != '\n');
    				continue;
			}
        }
    }
}

void afficher_releves(float temperatures[], int nb_releves) {
    printf("\n--- Releves enregistres ---\n");

    for (int i = 0; i < nb_releves; i++) {
        printf("Heure %02d : %.1f °C\n", i, temperatures[i]);
    }
}
