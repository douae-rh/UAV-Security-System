#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* 1. Topologie de la Donnée */
struct Drone {
    int id;
    float x;
    float y;
    float z;
};

/* Fonction de calcul de distance via pointeurs uniquement */
float calculerDistance(struct Drone *d1, struct Drone *d2) {
    float dx = (d1->x - d2->x);
    float dy = (d1->y - d2->y);
    float dz = (d1->z - d2->z);
    return sqrtf(dx*dx + dy*dy + dz*dz);
}

/* Comparateur pour le tri (basé sur l'axe X) */
int comparerX(const void *a, const void *b) {
    struct Drone *p1 = (struct Drone *)a;
    struct Drone *p2 = (struct Drone *)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}

int main() {
    const int N = 10000;
    
    /* 2. Verrouillage de la RAM (Le Tas) */
    struct Drone *essaim = (struct Drone *)malloc(N * sizeof(struct Drone));
    if (essaim == NULL) return 1;

    /* Initialisation de l'essaim (via pointeurs) */
    for (int i = 0; i < N; i++) {
        struct Drone *courant = (essaim + i); // Arithmétique de pointeurs
        courant->id = i;
        courant->x = (float)rand() / (float)RAND_MAX * 1000.0f;
        courant->y = (float)rand() / (float)RAND_MAX * 1000.0f;
        courant->z = (float)rand() / (float)RAND_MAX * 1000.0f;
    }

    /* Tri de l'essaim selon l'axe X (Théorie du tri pour optimisation) */
    qsort(essaim, N, sizeof(struct Drone), comparerX);

    float distanceMin = 1e10f;
    struct Drone *droneA = NULL;
    struct Drone *droneB = NULL;

    /* Recherche optimisée : on ne compare que les drones proches sur l'axe X */
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            struct Drone *pI = (essaim + i);
            struct Drone *pJ = (essaim + j);

            /* Si la distance sur X dépasse déjà la distanceMin, inutile de continuer */
            if ((pJ->x - pI->x) >= distanceMin) break;

            float d = calculerDistance(pI, pJ);
            if (d < distanceMin) {
                distanceMin = d;
                droneA = pI;
                droneB = pJ;
            }
        }
    }

    /* Affichage des résultats (Livrable industriel) */
    if (droneA && droneB) {
        printf("Alerte Collision Identifiee :\n");
        printf("Drone 1 ID: %d | Drone 2 ID: %d\n", droneA->id, droneB->id);
        printf("Distance: %.4f units\n", distanceMin);
    }

    free(essaim);
    return 0;
}