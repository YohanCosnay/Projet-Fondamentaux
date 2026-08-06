#ifndef SAISIE_H
#define SAISIE_H

#include "config.h"

/*
 * Demande à l'utilisateur de saisir les relevés de température.
 *
 * Paramètres :
 *  - temperatures : tableau contenant les températures
 *  - nb_releves   : nombre de relevés saisis
 */
void action_saisir(float *temperatures, int *nb_releves, Config *cfg);

/*
 * Affiche les relevés de température.
 *
 * Paramètres :
 *  - temperatures : tableau contenant les températures
 *  - nb_releves   : nombre de relevés
 */
void afficher_releves(float *temperatures, int nb_releves);

#endif /* SAISIE_H */
