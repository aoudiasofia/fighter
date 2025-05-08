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

    while (i < NBCOMBATTANTS && fscanf(f, "%49s %d %d %d %d %d %d %d",
                  nom,
                  &tab[i].points_de_vie_courants,
                  &tab[i].points_de_vie_max,
                  &tab[i].attaque,
                  &tab[i].defense,
                  &tab[i].agilite,
                  &tab[i].vitesse,
                  &indexTech) == 8) {

        // Copie dans la structure du combattant
        strcpy(tab[i].nom, nom);

        // Optionnel : pour un affichage global
        nomsCombattants[i] = malloc(strlen(nom) + 1);
        if (nomsCombattants[i]) strcpy(nomsCombattants[i], nom);

        tab[i].competencesSpeciales = tabTech[indexTech];

        i++;
    }

    fclose(f);

    if (i == 0) {
        printf("Aucun combattant lu depuis le fichier %s.\n", nomFichier);
    }

    return i;
}

