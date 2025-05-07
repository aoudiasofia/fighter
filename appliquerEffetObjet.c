#include <stdio.h>
#include "genererObjet.h"
#include "fichier.h" // Inclure la définition de la structure Combattants

void appliquerEffetObjet(Objet objet, Combattants* cible) {
    switch (objet.type) {
        case BOUCLIER:
            printf("%s utilise %s : %s\n", cible->nom, objet.nom, objet.description);
            // Augmente la défense du combattant
            cible->defense += 20; //ajoute 20 points de défense
            printf("La défense de %s augmente à %d.\n", cible->nom, cible->defense);
            break;

        case POTION:
            printf("%s utilise %s : %s\n", cible->nom, objet.nom, objet.description);
            // Restaure 50 PV au combattant
            cible->points_de_vie_courants += 50;
            if (cible->points_de_vie_courants > cible->points_de_vie_max) {
                cible->points_de_vie_courants = cible->points_de_vie_max; // Limite aux PV max
            }
            printf("Les PV de %s sont maintenant de %d/%d.\n", cible->nom, cible->points_de_vie_courants, cible->points_de_vie_max);
            break;

case TROLL:
   printf("%s utilise %s : %s\n", cible->nom, objet.nom, objet.description);
            // L'objet Troll n'a aucun effet
            printf("L'objet Troll n'a aucun effet sur %s.\n", cible->nom);
            break;

        default:
            printf("Objet inconnu. Aucun effet appliqué.\n");
            break;
    }
}