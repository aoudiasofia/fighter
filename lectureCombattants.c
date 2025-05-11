#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

int lectureCombattants(Combattants* tab, TechniqueSpeciale* tabTech, const char* nomFichier) {
    // Ouvre le fichier en mode lecture
    FILE* f = fopen(nomFichier, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return -1;
    }

    int i = 0;
    int indexTech;
    char nom[50];

    // Lecture des données des combattants
    while (i < NBCOMBATTANTS && 
           fscanf(f, "%49s %d %d %d %d %d %d %d", 
                  nom, 
                  &tab[i].points_de_vie_courants, 
                  &tab[i].points_de_vie_max,
                  &tab[i].attaque, 
                  &tab[i].defense, 
                  &tab[i].agilite, 
                  &tab[i].vitesse, 
                  &indexTech) == 8) {

        // Copie du nom dans la structure du combattant
        strcpy(tab[i].nom, nom);

        // Allocation dynamique pour nomsCombattants
        nomsCombattants[i] = malloc(strlen(nom) + 1);
        if (nomsCombattants[i] == NULL) {
            printf("Erreur d'allocation mémoire pour le nom du combattant %s.\n", nom);
            fclose(f);
            return -1; // Retourne une erreur si l'allocation échoue
        }
        strcpy(nomsCombattants[i], nom);

        // Associe la compétence spéciale au combattant
        if (indexTech >= 0 && indexTech < 10) { // Vérifie que l'index est valide
            tab[i].competencesSpeciales = tabTech[indexTech];
        } else {
            printf("Index de compétence invalide (%d) pour le combattant %s.\n", indexTech, nom);
            tab[i].competencesSpeciales.nom[0] = '\0'; // Définit une compétence vide
        }

        i++;
    }

    fclose(f); // Ferme le fichier après avoir lu tous les combattants

    // Vérifie si aucun combattant n'a été lu
    if (i == 0) {
        printf("Aucun combattant lu depuis le fichier %s.\n", nomFichier);
        return -1; // Retourne une erreur explicite si aucun combattant n'est lu
    }

    return i; // Retourne le nombre de combattants lus
}