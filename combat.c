#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include "affichage.h"
#include <unistd.h>

void combat(Equipe* bleue, Equipe* rouge, int mode, int niveauOrdinateur, float* jauges, int* vitesses) {

  int Combattant = choisirCombattantAJouer(jauges, vitesses, 4);
  printf("\n");


  //mode  
  if (mode == 1){ //2 joueurs 
    if (Combattant == -1) {
      //aucun combattant n'est prêt à jouer
      return;

    } else if (Combattant == 0) {
      if (bleue->membres[0].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", bleue->membres[0].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&bleue->membres[0], bleue);
      afficherActionsPossibles(&bleue->membres[0], bleue);

      // Demande si il veut utiliser un objet
      utiliserObjet(bleue,&(*bleue).membres[0]);
      gererTourHumain(&(*bleue).membres[0], (*rouge).membres, 2, (*bleue).membres, 2); // équipe bleue attaque rouge
        

    } else if (Combattant == 1) {
      if (bleue->membres[1].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", bleue->membres[1].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&bleue->membres[1], bleue);
      afficherActionsPossibles(&bleue->membres[1], bleue);
      utiliserObjet(bleue,&(*bleue).membres[1]);
      gererTourHumain(&(*bleue).membres[1], (*rouge).membres, 2, (*bleue).membres, 2); // équipe bleue attaque rouge

    } else if (Combattant == 2) {
      if (rouge->membres[0].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", rouge->membres[0].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&rouge->membres[0], rouge);
      afficherActionsPossibles(&rouge->membres[0], rouge);
  
      utiliserObjet(rouge,&(*rouge).membres[0]);
      gererTourHumain(&(*rouge).membres[0], (*bleue).membres, 2, (*rouge).membres, 2); // équipe rouge attaque bleue

    } else if (Combattant == 3){
      if (rouge->membres[1].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", rouge->membres[1].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&rouge->membres[1], rouge);
      afficherActionsPossibles(&rouge->membres[1], rouge);

      utiliserObjet(rouge,&(*rouge).membres[1]);
      gererTourHumain(&(*rouge).membres[1], (*bleue).membres, 2, (*rouge).membres, 2); // équipe rouge attaque bleue
    }
    
  }



  if (mode == 2){ //1 joueur contre l'ordinateur

    if (Combattant == -1) {
      //aucun combattant n'est prêt à jouer
      return;
      
    } else if (Combattant  == 0) {
      if (bleue->membres[0].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", bleue->membres[0].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&bleue->membres[0], bleue);
      afficherActionsPossibles(&bleue->membres[0], bleue);
      utiliserObjet(bleue,&(*bleue).membres[0]);
      gererTourHumain(&(*bleue).membres[0], (*rouge).membres, 2, (*bleue).membres, 2); // équipe bleue attaque rouge

    } else if (Combattant == 1) {
      if (bleue->membres[1].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", bleue->membres[1].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&bleue->membres[1], bleue);
      afficherActionsPossibles(&bleue->membres[1], bleue);
      utiliserObjet(bleue,&(*bleue).membres[1]);
      gererTourHumain(&(*bleue).membres[1], (*rouge).membres, 2, (*bleue).membres, 2); // équipe bleue attaque rouge

    } else if (Combattant == 2) {
      if (rouge->membres[0].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", rouge->membres[0].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&rouge->membres[0], rouge);
      afficherActionsPossibles(&rouge->membres[0], rouge);
      actionOrdinateur(&(*rouge).membres[0], rouge,bleue, 2,(*rouge).membres, niveauOrdinateur, 1); //l'ordinateur joue
      sleep(2);
    } else if (Combattant == 3) {
      if (rouge->membres[1].points_de_vie_courants <= 0) {
        printf("\033[1;31m⚠️ %s est KO et ne peut pas jouer !\033[0m\n", rouge->membres[1].nom);
        return;
      }
      afficherEtatCombat(*bleue, *rouge);
      afficherTourJoueur(&rouge->membres[1], rouge);
      afficherActionsPossibles(&rouge->membres[1], rouge);
      actionOrdinateur(&(*rouge).membres[1], rouge,bleue, 2,(*rouge).membres, niveauOrdinateur, 1);
      sleep(2);
    }
  }
  
  sleep(6); // Pause pour laisser le temps de lire
  system("clear");// Effacer l'écran

}    
     
   