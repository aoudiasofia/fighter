
#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 


void appliquerDegats(Combattants* cible, int degats) {
    int degatsReels = degats - (*cible).defense;
    if (degatsReels < 0) { //si les degats sont inférieurs à la défense
        degatsReels = 0; //0 degats appliqués
    }
    (*cible).points_de_vie_courants -= degatsReels;
    if ((*cible).points_de_vie_courants < 0) { //si les points de vie courants sont inférieurs à 0
        (*cible).points_de_vie_courants = 0; //on les met à 0
    }
    printf("%s subit %d dégâts (PV restants : %d). \n", (*cible).nom, degatsReels, (*cible).points_de_vie_courants);
    sleep(1);
}