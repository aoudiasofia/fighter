#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"


int lectureCombattants(Combattants* tab, TechniqueSpeciale* tabTech, const char* nomFichier) {
    FILE* f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return -1;
    }

    int i = 0;
    int indexTech;
    char nom[50];

    while (fscanf(f, "%49s %d %d %d %d %d %d",
                  nom,
                  &tab[i].points_de_vie_courants,
                  &tab[i].points_de_vie_max,
                  &tab[i].attaque,
                  &tab[i].defense,
                  &tab[i].agilite,
                  &tab[i].vitesse,
                  &indexTech) == 8) {

        // Copie du nom
        nomsCombattants[i] = malloc(strlen(nom) + 1);
        if (nomsCombattants[i]) strcpy(nomsCombattants[i], nom);

        // Copie de la compétence
        tab[i].competencesSpeciales = tabTech[indexTech];

        i++;
    }

    fclose(f);
    return i; // retourne le nombre de combattants chargés
}