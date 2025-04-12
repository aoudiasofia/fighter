#include "fichier.h"

// Définition globale de nomsCombattants
char* nomsCombattants[NBCOMBATTANTS];

// Autres fonctions
int lireCombattants(Combattants tab[], TechniqueSpeciale tabTech[], const char* nomFichier) {
    FILE* f = fopen(nomFichier, "r");

    if (f == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return -1;
    }

    int i = 0;
    int indexTech;
    char nom[50];

    // Lecture des combattants depuis le fichier
    while (fscanf(f, " \"%49[^\"]\" %d %d %d %d %d %d",
                  nom,
                  &tab[i].points_de_vie_courants,
                  &tab[i].points_de_vie_max,
                  &tab[i].attaque,
                  &tab[i].defense,
                  &tab[i].vitesse,
                  &indexTech) == 7) {
            
        // Affectation des compétences spéciales
        strcpy(tab[i].competencesSpeciales.nom, tabTech[indexTech].nom);
        tab[i].competencesSpeciales.valeur = tabTech[indexTech].valeur;
        strcpy(tab[i].competencesSpeciales.description, tabTech[indexTech].description);
        tab[i].competencesSpeciales.nbToursActifs = tabTech[indexTech].nbToursActifs;
        tab[i].competencesSpeciales.nbToursRecharge = tabTech[indexTech].nbToursRecharge;
        tab[i].competencesSpeciales.operation = tabTech[indexTech].operation;

// Allocation de mémoire pour le nom du combattant
        nomsCombattants[i] = malloc(strlen(nom) + 1);
if (nomsCombattants[i] != NULL) {
    strcpy(nomsCombattants[i], nom);
} else {
    printf("Erreur d'allocation mémoire pour le nom du combattant %d\n", i);
}

        // Vérification pour ne pas dépasser le nombre maximum de combattants
        if (i >= NBCOMBATTANTS) {
            break;
        }
    }

    fclose(f);
    return i;
}