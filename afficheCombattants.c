#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* nomsCombattants[NBCOMBATTANTS];
Combattants tab[NBCOMBATTANTS];

int main() {
    TechniqueSpeciale tabTech[10];

    // Initialisation
    for (int i = 1; i <= NBCOMBATTANTS; i++) {
        nomsCombattants[i] = NULL;
    }

    lectureTechniques(tabTech, "TechniquesSpeciales.txt");
    lectureCombattants(tab, tabTech, "Combattants.txt");

    for (int i = 0; i < NBCOMBATTANTS; i++) {
        printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s \n",i,
               nomsCombattants[i],
               tab[i].points_de_vie_max,
               tab[i].attaque,
               tab[i].vitesse,
               tab[i].competencesSpeciales.nom);
    }

    // Libérer mémoire noms
    for (int i = 0; i < NBCOMBATTANTS; i++) {
        free(nomsCombattants[i]);
    }

    return 0;
}