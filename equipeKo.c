#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"


int equipeEstKO(Equipe* eq) {
    for (int i = 0; i < 2; i++) {
        if (eq->membres[i].points_de_vie_courants > 0) { //vérifie si le combattant n'a plus de points de vie 
            return 0; // L'équipe n'est pas KO
        }
    }
    return 1; // Tous les membres de l'équipe sont KO 
}