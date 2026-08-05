float calculer_moyenne(float *tab, int n) {
    float somme = 0.0;

    for (int i = 0; i < n; i++) {
        somme += tab[i];
    }

    return somme / n;
}

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

float calculer_amplitude(float *tab, int n) {
    int *idx_min;
    int *idx_max;

    return trouver_maximum(tab, n, idx_max) - trouver_minimum(tab, n, idx_min);
}
