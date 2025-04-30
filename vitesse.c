#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //pour sleep

#define COEF 1.0
#define MAX_JAUGE 100

int main() {
    FILE* f;
    f = fopen("combattants.txt", "r"); //ouverture du fichier en lecture
    if(f == NULL){
        printf("Erreur d'ouverture du fichier\n");
        exit(1);
    }
    char ligne[100];
    int vitesse[NBCOMBATTANTS];
    char noms[NBCOMBATTANTS][50];https://github.com/aoudiasofia/fighter
    float jauges[NBCOMBATTANTS] = {0}; //initialisation des jauges de vitesse à 0

    //lecture du fichier et récuperation des vitesses
    for(int i = 1; i<=NBCOMBATTANTS; i++){
        fgets(ligne, sizeof(ligne), f); //lire une ligne du fichier  
        int stats[7];//nombre de statistique d'un perso
        fscanf(ligne, "%d %d %d %d %d %d %d", &stats[0], &stats[1], &stats[2], &stats[3], &stats[4], &stats[5], &stats[6]); //récupérer les stats du perso
        vitesse[i] = stats[5]; //récupérer la vitesse du perso
    }
    fclose(f); //fermeture du fichier

    //jauge
    int tour_du_joueur = -1; //joueur qui n'existe pas
    float jauge_inter = 0; //jauge intermédiaire

    while(1){
        for(int i = 1; i<=NBCOMBATTANTS; i++){
            jauges[i] += vitesse[i] * COEF /100; //calcul de la jauge
        }
        for(int i = 1; i<=NBCOMBATTANTS; i++){
            if(jauges[i] >= MAX_JAUGE){ //si la jauge est supérieur à 100
                if(jauges[i] > jauge_inter){ //si la jauge est supérieur à la jauge intermédiaire
                    jauge_inter = jauges[i]; //mise à jour de la jauge intermédiaire
                    tour_du_joueur = i; //mise à jour du joueur qui joue
                }
            }
        }
        if(tour_du_joueur != -1){ //si un joueur peut jouer
            printf("%s joue\n", noms[tour_du_joueur]); //affichage du joueur qui joue
            jauges[tour_du_joueur] = 0; //remise à zéro de la jauge du joueur
            tour_du_joueur = -1; //remise à zéro du joueur qui joue
            jauge_inter = 0; //remise à zéro de la jauge intermédiaire
        }
        sleep(1); //pause de 1 secondes
    }
    return tour_du_joueur; //retourne le joueur qui joue.
}