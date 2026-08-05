#ifndef TEMPERATURE_INPUT_H
#define TEMPERATURE_INPUT_H

#define MAX_RELEVES 24
#define TEMP_MIN -50.0
#define TEMP_MAX 60.0

void saisir_releves(float temperatures[], int *nb_releves);
void afficher_releves(float temperatures[], int nb_releves);

#endif
