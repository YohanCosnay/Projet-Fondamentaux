#ifndef ALERTE_H
#define ALERTE_H

#include <stdio.h>
#include "config.h"

void analyser_alertes(float *tab, int n, Config *cfg);
void Modifier_seuils_alerte(Config *cfg);

#endif