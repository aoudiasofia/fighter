#include "fichier.h"

int main() {
    Combattants tab[NBCOMBATTANTS];
    TechniqueSpeciale tabTech[NBCOMBATTANTS]; 

    // Initialisez les noms des combattants à NULL
    for (int i = 0; i < NBCOMBATTANTS; i++) {
        nomsCombattants[i] = NULL;
    }

    // Chargez les techniques spéciales
    lireTechniques(tabTech, "TechniquesSpeciales.txt");

    // Chargez les combattants depuis un fichier
    lireCombattants(tab, tabTech, "Combattants.txt");

    // Affichez les combattants
    for (int i = 0; i < NBCOMBATTANTS; i++) {
        if (nomsCombattants[i] != NULL) {
            printf("%s -> PV: %d - Technique: %s\n",
                   nomsCombattants[i], tab[i].points_de_vie_max, tab[i].competencesSpeciales.nom);
        } else {
            printf("Combattant %d non initialisé\n", i);
        }
    }

    // Libérez la mémoire allouée pour les noms des combattants
    for (int i = 0; i < NBCOMBATTANTS; i++) {
        free(nomsCombattants[i]);
    }

    return 0;
}