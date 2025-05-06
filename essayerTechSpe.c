#include "fichier.h"

int essayerUtiliserTechniqueSpeciale(Combattants joueur, int index, int compteurRecharge[], TechniqueSpeciale techniques[]) { //tableau de techniques spéciales, index ; numéro de joueur qui vient de jouer
    TechniqueSpeciale tech = techniques[index];

    printf("  Technique spéciale de %s : (Rechargée : %d / %d tours)\n", 
           joueur.nom, compteurRecharge[index], tech.nbToursRecharge);

    if (compteurRecharge[index] >= tech.nbToursRecharge) {
        printf(" %s peut utiliser %s\n",joueur.nom , tech.nom);
        compteurRecharge[index] = 0; // reset du compteur
        return 1; // peut utiliser la technique
        
    } else {
        printf("  Technique pas encore prête\n");
        compteurRecharge[index]++; // incrémentation
        return 0; // attaque de base
    }
}