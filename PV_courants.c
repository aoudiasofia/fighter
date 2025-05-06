#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGUEUR_JAUGE 100

void recupererStats(Combattants *combattant) {
    FILE* f;
    f = fopen("combattants.txt", "r"); //ouverture du fichier en lecture
    if(f == NULL){
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }
    for(int i = 1; i <= NBCOMBATTANTS; i++) {
        fscanf(f, "%s %d %d", combattant[i].nom, &combattant[i].points_de_vie_courants, &combattant[i].points_de_vie_max); //recuperer les stats du perso
    }
    fclose(f);
}

void afficherJaugePV(Combattants combattant){
    int jauge = (combattant.points_de_vie_courants * LONGUEUR_JAUGE) / combattant.points_de_vie_max;
    printf("Jauge de vie de %s : [", combattant.nom);
    for(int i = 0; i < LONGUEUR_JAUGE; i++){
        if(i < jauge){
            printf("#"); //Affiche un "#" pour chaque point de vie 
        }else{
            printf(" "); 
        }
    }
    printf("]\n");
}