
#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"


void appliquerEffetObjet(Objet objet, Combattants* cible) {
    printf("%s utilise %s : %s \n", (*cible).nom, objet.nom, objet.description);

    switch (objet.type) {
        case BOUCLIER:
            // Augmente la défense du combattant
            (*cible).defense += 20;
            printf("La défense de %s augmente à %d.\n", (*cible).nom, (*cible).defense);
            break;

        case POTION:
            // Restaure 50 PV au combattant
            (*cible).points_de_vie_courants += 50;
            if ((*cible).points_de_vie_courants > (*cible).points_de_vie_max) {
                (*cible).points_de_vie_courants = (*cible).points_de_vie_max;
            }
            printf("Les PV de %s sont maintenant de %d/%d.\n", (*cible).nom, (*cible).points_de_vie_courants, (*cible).points_de_vie_max);
            break;

        case TROLL:
            // L'objet Troll n'a aucun effet
            printf("L'objet Troll n'a aucun effet sur %s.\n", (*cible).nom);
            break;

        default:
            printf("Objet de type inconnu (%d). Aucun effet appliqué à %s.\n", objet.type, (*cible).nom);
            break;
    }
}




int peutUtiliserObjet(Objet objet, Equipe* eq) {
    // Vérifier si l'objet a déjà été utilisé
    if ((*eq).objetUtilise != 0) {
        printf("L'objet %s a déjà été utilisé. Vous ne pouvez plus l'utiliser.\n", objet.nom);
        return 0; // L'objet ne peut pas être utilisé
    }

    // Vérifier si l'objet est de type TROLL
    if (objet.type == TROLL) {
        return 0; // L'objet ne peut pas être utilisé
    }

    // Si aucune des conditions ci-dessus n'est remplie, l'objet peut être utilisé
    return 1; // L'objet peut être utilisé
}


void utiliserObjet(Equipe* eq, Combattants* utilisateur) {
    int choix;

    if (peutUtiliserObjet((*eq).objet, eq) == 0) {
        printf("L'objet a déjà été utilisé ou il s'agit d'un TROLL. Vous ne pouvez pas l'utiliser.\n");
        return;
    }

    // Proposer au joueur d'utiliser l'objet
    do {
        printf("Votre équipe possède l'objet : %s (%s)\n", (*eq).objet.nom, (*eq).objet.description);
        printf("Souhaitez-vous utiliser cet objet sur %s ?\n", (*utilisateur).nom);
        printf("Entrer 1 pour OUI, 2 pour NON : ");

        if (scanf(" %d", &choix) != 1) {
            printf("Entrée invalide. Veuillez entrer 1 ou 2.\n");
            viderBuffer(); // Nettoie le buffer en cas de mauvaise entrée
            choix = 0; // Force la répétition de la boucle
        } else {
            viderBuffer(); // Nettoie le buffer après une bonne entrée
        }
    } while (choix != 1 && choix != 2);

    if (choix == 1) {
        appliquerEffetObjet((*eq).objet, utilisateur);
        (*eq).objetUtilise = 1;
    } else {
        printf("Vous avez choisi de ne pas utiliser l'objet.\n");
    }
}
