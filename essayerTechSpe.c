
#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int essayerUtiliserTechniqueSpeciale(Combattants* joueur, TechniqueSpeciale tech) {
    printf("  Technique spéciale de %s : (Rechargée : %d / %d tours)\n", 
           joueur->nom, joueur->competencesSpeciales.jauge, tech.nbToursRecharge);

    if (joueur->competencesSpeciales.jauge >= tech.nbToursRecharge) {
        printf(" %s peut utiliser %s\n", joueur->nom, tech.nom);
        joueur->competencesSpeciales.jauge = 0; // reset du compteur
        return 1; // peut utiliser la technique
    } else {
        printf("  Technique pas encore prête\n");
        joueur->competencesSpeciales.jauge++; // incrémentation
        return 0; // attaque de base
    }
}