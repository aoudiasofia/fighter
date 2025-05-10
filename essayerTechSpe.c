
#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int essayerUtiliserTechniqueSpeciale(Combattants* joueur) {
   
    if (joueur->competencesSpeciales.jauge >= joueur->competencesSpeciales.nbToursRecharge) {
        printf(" %s peut utiliser %s\n", joueur->nom, joueur->competencesSpeciales.nom);
        return 1; // peut utiliser la technique
    } else {
       
        return 0; // attaque de base
    }
}