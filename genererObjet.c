
//fonxtion qui génère un objet aléatoire
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fichier.h"

//fonction qui génère un objet aléatoire 

Objet genererObjetAleatoire() {
    Objet objet;
    int r = rand() % 3;
    switch (r) {
        case 0:
            objet.type = BOUCLIER;
            strcpy(objet.nom, "Bouclier");
            strcpy(objet.description, "Augmente la défense du combattant");
            break;
        case 1:
            objet.type = POTION;
            strcpy(objet.nom, "Potion de vie");
            strcpy(objet.description, "Rend 50 PV à un combattant.");
            break;
        case 2:
            objet.type = TROLL;
            strcpy(objet.nom, "Troll");
            strcpy(objet.description, "Ne fait rien...");
            break;
    }
    return objet;
}
