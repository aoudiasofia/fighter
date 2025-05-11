// procedure pour afficher l'objet obtenue par le joueur 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"
#include <unistd.h>  // Pour la fonction sleep() 


void afficherObjet(Objet objet) {
    switch (objet.type) {
        case BOUCLIER:
            printf("Type : Bouclier 🛡️ \n"); 
            break;
        case POTION:
            printf("Type : Potion 🧪\n"); 
            break;
        case TROLL:
            printf("Type : Troll 🧌 \n"); 
    }
}

// Fonction pour afficher l'animation de chargement
void afficherChargement() {
    printf("Chargement de l'objet");
    fflush(stdout); // S'assure que le texte est affiché immédiatement
    for (int i = 0; i < 3; i++) {
        sleep(1);  // Attend une seconde
        printf(".");  // Affiche un point à chaque seconde
        fflush(stdout); // Force l'affichage immédiat du point
    }
    printf("\n"); // Passe à la ligne après l'animation
}


void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}