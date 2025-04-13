#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Combattants equipebleu[2], equiperouge[2];


int mode;
int choix1, choix2, choix3, choix4;


int main(){
//Declaration 
int mode;
int choix1, choix2, choix3, choix4;
//Choix du mode de jeu
  printf("Bienvenue\n");
  printf("Mode 1 : 2 joueurs\n");
  printf("Mode 2 : 1 joueur contre l'ordinateur\n");
  do{
  printf("Choisissez le mode de jeu :\n");
  } while (mode != 1 && mode != 2);
  printf("Vous avez choisi le mode %d\n", mode);
  
    //Equipe bleu 
    //afficher les combattants 
  printf ("Choisissez le 2 Combattants de l'équipe bleue parmis : \n");
 
  for (int i = 0; i < NBCOMBATTANTS; i++) {
    printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s\n",i,nomsCombattants[i],tab[i].points_de_vie_max, tab[i].attaque,tab[i].vitesse, tab[i].competencesSpeciales.nom);
  }

  //premier choix 
  
  do{
  printf("Choisissez le premier combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
  scanf("%d",choix1);
  } while(choix1<0 || choix1>=NBCOMBATTANTS);


  //second choix 
  
  do{
  printf("Choisissez le deuxième combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
  printf("Attention, il ne doit pas être le même que le premier !\n");
  printf("Choix : ");
  scanf("%d",choix2);
  } while((choix1==choix2) || (choix2<0 || choix2>=NBCOMBATTANTS));


  //Pour l'équipe rouge deux possibilités 
  //soit le joueur2 choisit son equipe 
  //soit le joueur1 joue contre l'ordi et on choisit aléatoirement

  

  if (mode == 1){
  //Cas 1 : 
  printf("Rappelons les combattants disponibles : ")
  for (int i = 0; i < NBCOMBATTANTS; i++) {
    printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s\n",i,nomsCombattants[i],tab[i].points_de_vie_max, tab[i].attaque,tab[i].vitesse, tab[i].competencesSpeciales.nom);
  }
  //premier choix
  do{
  printf("Choisissez le premier combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
  scanf("%d",choix3);
  } while(choix3<0 || choix3>=NBCOMBATTANTS);
  //second choix
  do{
  printf("Choisissez le deuxième combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
  printf("Attention, il ne doit pas être le même que le premier !\n");
  printf("Choix : ");
  scanf("%d",choix4);
  } while((choix3==choix4) || (choix4<0 || choix4>=NBCOMBATTANTS));
  } else if (mode==2){
  //Cas 2 :
  //On choisit aléatoirement
  srand(time(NULL));
  choix3 = rand() % NBCOMBATTANTS;
  choix4 = rand() % NBCOMBATTANTS;
  while (choix3 == choix4) {
    choix4 = rand() % NBCOMBATTANTS;
  }
  printf("L'ordinateur a choisi les combattants suivants :\n");
  printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s\n",choix3,nomsCombattants[choix3],tab[choix3].points_de_vie_max, tab[choix3].attaque,tab[choix3].vitesse, tab[choix3].competencesSpeciales.nom);
  printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s\n",choix4,nomsCombattants[choix4],tab[choix4].points_de_vie_max, tab[choix4].attaque,tab[choix4].vitesse, tab[choix4].competencesSpeciales.nom);
  }

}