#ifndef CONFIG_H
#define CONFIG_H

/* Nombre maximal de relevés */
#define MAX_RELEVES 24

/* Plage de températures autorisées */
#define TEMP_MIN -50.0f
#define TEMP_MAX 60.0f

/* Hauteur maximale de l'histogramme */
#define HISTO_HAUTEUR 5

/*
 * Structure contenant les paramètres
 * configurables du programme.
 */
typedef struct {
    float seuil_chaud;      /* alerte CANICULE si température >= seuil */
    float seuil_froid;      /* alerte GEL si température <= seuil      */
    float seuil_amplitude;  /* alerte ECART si amplitude >= seuil      */
} Config;

#endif /* CONFIG_H */
