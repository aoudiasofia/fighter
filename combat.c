#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void combat(Equipe* bleue, Equipe* rouge, int mode, int niveauOrdinateur, float* jauges, int* vitesses) {

  int Combattant = choisirCombattantAJouer(jauges, vitesses, 4);
  
printf("\n");
    
    //mode 
    if (mode==1){ //2 joueurs 

     if (Combattant == -1) {
      //aucun combattant n'est prêt à jouer
       return;

    } else if (Combattant == 0) {
        printf("C'est au tour de %s de jouer.\n", bleue->membres[0].nom);

        // Demande si il veut utiliser un objet
        utiliserObjet(bleue,&(*bleue).membres[0]);
        essayerUtiliserTechniqueSpeciale(&(*bleue).membres[0], (*bleue).membres[0].competencesSpeciales); //equipe bleue attaque rouge adversiares
        gererTourHumain(&(*bleue).membres[0], (*rouge).membres, 2); //equipe bleue attaque rouge adversiares


      } else if (Combattant == 1) {
          printf("C'est au tour de %s de jouer.\n", bleue->membres[1].nom);

          utiliserObjet(bleue,&(*bleue).membres[1]);
          essayerUtiliserTechniqueSpeciale(&(*bleue).membres[1], (*bleue).membres[1].competencesSpeciales);
          gererTourHumain(&(*bleue).membres[1], (*rouge).membres, 2); //equipe bleue attaque rouge adversiares


       } else if (Combattant == 2) {
          printf("C'est au tour de %s de jouer.\n", rouge->membres[0].nom);

          utiliserObjet(rouge,&(*rouge).membres[0]);
          essayerUtiliserTechniqueSpeciale(&(*rouge).membres[0], (*rouge).membres[0].competencesSpeciales);
          gererTourHumain(&(*rouge).membres[0], (*bleue).membres, 2); //equipe rouge attaque bleue adversiares


        } else if (Combattant == 3){
            printf("C'est au tour de %s de jouer.\n", rouge->membres[1].nom);

            utiliserObjet(rouge,&(*rouge).membres[1]);
            essayerUtiliserTechniqueSpeciale(&(*rouge).membres[1], (*rouge).membres[1].competencesSpeciales);
            gererTourHumain(&(*rouge).membres[1], (*bleue).membres, 2); //equipe rouge attaque bleue adversiares
          }
    }



  if (mode == 2){ //1 joueur contre l'ordinateur

    if (Combattant == -1) {
      //aucun combattant n'est prêt à jouer
      return;
      
    } else if (Combattant  == 0) {
        printf("C'est au tour de %s de jouer.\n", (*bleue).membres[0].nom);
        gererTourHumain(&(*bleue).membres[0],(*rouge).membres, 2); //equipe bleue attaque rouge adversiares

      } else if (Combattant == 1) {
          printf("C'est au tour de %s de jouer.\n", (*bleue).membres[1].nom);
          gererTourHumain(&(*bleue).membres[1],(*rouge).membres, 2); //equipe bleue attaque rouge adversiares

        } else if (Combattant == 2) {
          printf("C'est au tour de %s de jouer.\n", (*rouge).membres[0].nom);
            actionOrdinateur(&(*rouge).membres[0], rouge,bleue, niveauOrdinateur); //l'ordinateur joue

          } else if (Combattant == 3) {
            printf("C'est au tour de %s de jouer.\n", (*rouge).membres[1].nom);
              actionOrdinateur(&(*rouge).membres[1],rouge, bleue, niveauOrdinateur); //l'ordinateur joue
            }
  }

}    
     
   