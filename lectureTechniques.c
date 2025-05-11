#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"


int lectureTechniques(TechniqueSpeciale* techniques, const char* nomFichier) {
    FILE* f = fopen(nomFichier, "r"); // Ouvre le fichier en mode lecture
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return -1;
    }

    int i = 0;
    while (fscanf(f, " \"%49[^\"]\" %f \"%199[^\"]\" %d %d %d",
                  techniques[i].nom,
                  &techniques[i].valeur,
                  techniques[i].description,
                  &techniques[i].nbToursRecharge,
                  &techniques[i].nbToursActif,
                  &techniques[i].jauge)  == 6) { // Lit les lignes du fichier
        i++;
    }

    fclose(f);
    return i; // retourne le nombre de techniques lues
}