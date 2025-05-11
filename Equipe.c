#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>  // Pour la fonction sleep()
#include "couleurs.h"


Combattants equipebleue[2], equiperouge[2];
Equipe equipeBleue, equipeRouge;



int main() {
  //initialisation générateur aléatoire 
  srand(time(NULL));

 
  // Lecture des données
  TechniqueSpeciale tabTech[10];
  lectureTechniques(tabTech, "TechniquesSpeciales.txt");
  lectureCombattants(tab, tabTech, "Combattants.txt");

  // Déclaration 
  // Initialiser la jauge des techniques spéciales de tous les combattants à 0
  for (int i = 0; i < NBCOMBATTANTS; i++) {
    tabTech[i].jauge = 0;
  }
  // Initialiser les objets utilisés à 0
  equipeBleue.objetUtilise = 0;
  equipeRouge.objetUtilise = 0;

  int mode;
  int choix1 = 0, choix2 = 0, choix3 = 0, choix4 = 0;

  // Choix du mode de jeu

  printf("=============================================\n");
  printf("🎮 %sBienvenue dans le jeu CY-FIGHTERS 🥊%s\n",VIOLET , RESET);
  printf("=============================================\n\n");
  sleep(1); // Pause de 1 seconde pour l'effet d'animation

  printf("📜 %sRègles du jeu :%s\n", VIOLET, RESET);
  sleep(1);
  printf("- Chaque joueur choisit 2 combattants\n");
  sleep(1);
  printf("- Chaque équipe a un objet bonus mystère 🎁\n");
  sleep(1);

  printf("- Le but : mettre l’équipe adverse K.O. 💀\n\n");
  sleep(2);

  printf("=============================================\n");
  printf("Sélection du mode de jeu :\n");
  sleep(1);
  printf("1️⃣  Mode 2 Joueurs\n");
  sleep(1);
  printf("2️⃣  Mode 1 Joueur contre l'ordinateur\n");
  printf("=============================================\n\n");
  sleep(1);
  printf("\n");

  //######## choix mode de jeu ########
  do {
    printf("Choisissez le mode de jeu (1 ou 2) : ");
    int saisitOK = scanf("%d", &mode);
    viderBuffer(); // Vider le buffer d'entrée pour éviter les erreurs de saisie

    if (saisitOK != 1 || (mode != 1 && mode != 2)) {
      printf("%s⚠️ Choix invalide ! Veuillez entrer 1 ou 2 🤦%s\n",ROUGE,RESET);
      mode = 0; // Réinitialiser pour forcer une nouvelle saisie
    }
  } while (mode != 1 && mode != 2);

  printf("\n");
  printf("Vous avez choisi le mode %d\n", mode);
  printf("\n");
  sleep(1);
  //FIN CHOIX MODE DE JEU 


  //######## choix niveau de difficulté ########

  // a mettre après avoir choisi de prendre l'ordinateur:
  int niveau = 0; // Niveau de difficulté de l'ordinateur

  if (mode == 2) {
    printf("Choisissez le niveau de difficulté de l'ordinateur :\n");
    printf("1 : Noob (attaque aléatoire, pas de technique spéciale)\n");
    printf("2 : Facile (attaque celui avec le moins de PV, pas de technique spéciale)\n");
    printf("3 : Moyen (attaque celui avec le moins de PV, utilise la technique spéciale si disponible)\n");
    do {
      printf("Entrez le niveau (1, 2 ou 3) : ");
      int saisitOK = scanf("%d", &niveau);
      viderBuffer(); // Vider le buffer d'entrée pour éviter les erreurs de saisie
      if (saisitOK != 1) {
        printf("%s⚠️ Entrée invalide ! Veuillez entrer un numéro valide%s 🤦\n",ROUGE , RESET);
        niveau = 0; // Forcer la répétition de la boucle
      } else if (niveau < 1 || niveau > 3) {
        printf("⚠️ %sLe niveau doit être compris entre 1 et 3%s 🤦\n", ROUGE, RESET);
      }
    } while (niveau < 1 || niveau > 3);
    printf("Vous avez choisi le niveau %d\n", niveau);
    printf("\n");
    sleep(1);
  }   
  //######FIN CHOIX NIVEAU DE DIFFICULTE#######

  //EQUIPE BLEUE
  //afficher les combattants 
  printf ("Choisissez le 2 Combattants de %sl'équipe bleue%s 🔵 parmis : \n", BLEU,RESET);
  printf("\n");
  for (int i = 0; i < NBCOMBATTANTS; i++) {
    printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s\n",i,nomsCombattants[i],tab[i].points_de_vie_max, tab[i].attaque,tab[i].vitesse, tab[i].competencesSpeciales.nom);
    sleep(1); // Pause de 1 seconde 
  }
  printf("\n");

  //Premier choix de l'equipe bleue 
  do {
    printf("Choisissez le premier combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
    printf("\n");
    printf("Choix 1 : ");
    int saisitOK1 = scanf("%d", &choix1);
    viderBuffer(); // Vider le buffer d'entrée pour éviter les erreurs de saisie

    if (saisitOK1 != 1) {
      printf("⚠️ Entrée invalide ! Veuillez entrer un numéro valide.\n");
      choix1 = -1; // Forcer la répétition de la boucle
    } else if (choix1 < 0 || choix1 >= NBCOMBATTANTS) {
      printf("⚠️ Le numéro doit être compris entre 0 et %d.\n", NBCOMBATTANTS - 1);
    }

  } while (choix1 < 0 || choix1 >= NBCOMBATTANTS);


  //second choix 

  printf("\n");
  printf("Choisissez le deuxième combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
  printf("⚠️ Attention, il ne doit pas être le même que le premier !\n");
  do {
    printf("Choix 2 : ");
    int saisitOK2 = scanf("%d", &choix2);
    viderBuffer(); // Vider le buffer d'entrée pour éviter les erreurs de saisie
    printf("\n");
    if (saisitOK2 != 1) {
      printf("⚠️ Entrée invalide ! Veuillez entrer un numéro valide.\n");
      choix2 = -1; // Forcer la répétition de la boucle
    } else if (choix1 == choix2) {
      printf("⚠️ Attention, il ne doit pas être le même que le premier !\n");
    } else if (choix2 < 0 || choix2 >= NBCOMBATTANTS) {
      printf("⚠️ Le numéro doit être compris entre 0 et %d.\n", NBCOMBATTANTS - 1);
    }
  } while ((choix1 == choix2) || (choix2 < 0 || choix2 >= NBCOMBATTANTS));

  // Affectation maintenant que les choix sont valides
  equipebleue[0] = tab[choix1];
  equipebleue[1] = tab[choix2];

  // FIN EQUIPE BLEUE

  //EQUIPE ROUGE
  //Pour l'équipe rouge deux possibilités 
  //soit le joueur2 choisit son equipe 
  //soit le joueur1 joue contre l'ordi et on choisit aléatoirement

  if (mode == 1){ //2 joueurs
    //Cas 1 : 
    printf("Rappelons les combattants disponibles : ");
    printf("\n");
    for (int i = 0; i < NBCOMBATTANTS; i++) {
      printf("%d %s → PV max : %d | Attaque : %d | Vitesse : %d | Compétence : %s\n",i,nomsCombattants[i],tab[i].points_de_vie_max, tab[i].attaque,tab[i].vitesse, tab[i].competencesSpeciales.nom);
      sleep(1); // Pause de 1 seconde 
    }
    printf("\n");
    printf("On vous rappelle que %s%s et %s%s ont deja été choisi\n",BLEU,nomsCombattants[choix1],nomsCombattants[choix2],RESET);
    printf("Choisissez les 2 Combattants de %sl'équipe rouge%s 🔴 parmis ceux qui n'ont pas été choisi : \n",ROUGE,RESET);

    //premier choix 
    do {
    
      printf("Choisissez le premier combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
      printf("\n");
      printf("Choix 1 : ");
      int saisitOK3 = scanf("%d", &choix3);
      viderBuffer(); // Vider le buffer d'entrée pour éviter les erreurs de saisie
      printf("\n");

      if (saisitOK3 != 1) {
        printf("⚠️ Entrée invalide ! Veuillez entrer un numéro valide.\n");
        choix3 = -1; // Forcer la répétition de la boucle
      } else if (choix3 < 0 || choix3 >= NBCOMBATTANTS) {
        printf("⚠️ Le numéro doit être compris entre 0 et %d.\n", NBCOMBATTANTS - 1);
      }
    } while (choix3 < 0 || choix3 >= NBCOMBATTANTS || choix3 == choix1 || choix3 == choix2); // Vérifier que le choix est valide et n'est pas déjà pris

   

    //second choix
    printf("Choisissez le deuxième combattant à l'aide de son numéro (0 à %d) : ", NBCOMBATTANTS - 1);
    printf("⚠️ Attention, il ne doit pas être déjà choisi !\n");
    do {
      printf("Choix 2 : ");
      int saisitOK4 = scanf("%d", &choix4);
      viderBuffer(); // Vider le buffer d'entrée pour éviter les erreurs de saisie
      printf("\n");
      
      if (saisitOK4 != 1) {
        printf("⚠️ Entrée invalide ! Veuillez entrer un numéro valide.\n");
        choix4 = -1; // Forcer la répétition de la boucle
      } else if (choix3 == choix4) {
        printf("⚠️ Attention, il ne doit pas être le même que le premier !\n");
      } else if (choix4 < 0 || choix4 >= NBCOMBATTANTS) {
        printf("⚠️ Le numéro doit être compris entre 0 et %d.\n", NBCOMBATTANTS - 1);
      }
    } while ((choix3 == choix4) || (choix4 < 0 || choix4 >= NBCOMBATTANTS) || choix4 == choix1 || choix4 == choix2); // Vérifier que le choix est valide et n'est pas déjà pris
 
    // Affectation maintenant que les choix sont valides
    equiperouge[0] = tab[choix3];
    equiperouge[1] = tab[choix4];

  } else if (mode==2){ //1 joueur contre l'ordinateur
    //Cas 2 :
    //On choisit aléatoirement

    do{ // le premier combattant en vérifiant qu'il n'a pas été déjà pris 
      choix3 = rand() % NBCOMBATTANTS;
    } while (choix3 == choix1 || choix3 == choix2);

    do{ // le second combattant en vérifiant qu'il n'a pas été déja prix 
      choix4 = rand() % NBCOMBATTANTS;
    } while (choix4 == choix1 || choix4 == choix2 || choix3 == choix4);
  

    //On affiche les choix de l'ordinateur
    printf( "\n");
    printf("L'ordinateur a choisi les combattants suivants :\n");
    printf("\n");
    printf(" %s\n",nomsCombattants[choix3]);
    sleep(1);
    printf(" %s\n",nomsCombattants[choix4]);
    sleep(1);
  
    // Affectation maintenant que les choix sont valides
    equiperouge[0] = tab[choix3];
    equiperouge[1] = tab[choix4];  
  }

  printf("\n");
  printf("Vos choix on bien été pris en compte !\n");
  sleep(1);
  
  //On affiche les équipes
  printf("\033[1;34m L'Equipe BLEUE \033[0m est composée de : ");
  printf(" %s et %s \n",nomsCombattants[choix1],nomsCombattants[choix2]);
  sleep(1);
  printf("\033[1;31m L'Equipe ROUGE \033[0m est composée de : ");
  printf(" %s et %s \n",nomsCombattants[choix3],nomsCombattants[choix4]);
  sleep(1);
  printf("\n");
  printf("\n");

  //LES OBJETS 

  printf("Dans ce jeu chaque joueur à le droit aléatoirement à un OBJET BONUS 🙌 \n");
  printf("\n");
  printf("\n");

  //On choisit aléatoirement un objet bonus pour chaque équipe

  // Déclaration des objets
  Objet objetBleu = genererObjetAleatoire();
  Objet objetRouge = genererObjetAleatoire();

  // Affichage avec couleurs et emojis

  printf("\033[1;34m🔵 Appuie sur Entrée pour afficher l'objet de l'équipe bleue 🔵\033[0m\n"); 
  getchar();     // Attente réelle de la touche
  afficherChargement();  // Animation de chargement
  afficherObjet(objetBleu);  // Afficher l'objet de l'équipe bleue

  printf("\033[1;31m🔴 Appuie sur Entrée pour afficher l'objet de l'équipe rouge 🔴\033[0m\n"); 
  getchar(); // Attendre la pression de la touche Entrée

  afficherChargement();  // Animation de chargement
  afficherObjet(objetRouge);  // Afficher l'objet de l'équipe rouge
  sleep(1); // Pause de 1 seconde pour l'effet d'animation


  equipeBleue.membres[0] = tab[choix1]; // Affectation du premier combattant de l'équipe bleue
  equipeBleue.membres[1] = tab[choix2]; // Affectation du deuxième combattant de l'équipe bleue
  equipeBleue.objet = objetBleu; // Affectation de l'objet de l'équipe bleue
  
  equipeRouge.membres[0] = tab[choix3]; // Affectation du premier combattant de l'équipe rouge
  equipeRouge.membres[1] = tab[choix4]; // Affectation du deuxième combattant de l'équipe rouge
  equipeRouge.objet = objetRouge; // Affectation de l'objet de l'équipe rouge

  sleep(4); // Pause de 2 secondes pour laisser le temps de lire
  system("clear");// Effacer l'écran


  //COMBAT
  // Initialiser les jauges et vitesses
  float jauges[4] = {0, 0, 0, 0};
  int vitesses[4];
  vitesses[0] = equipeBleue.membres[0].vitesse;
  vitesses[1] = equipeBleue.membres[1].vitesse;
  vitesses[2] = equipeRouge.membres[0].vitesse;
  vitesses[3] = equipeRouge.membres[1].vitesse;

  printf("%sMAINTENANT PLACE AU COMBAT !!!!!%s\n",VIOLET, RESET);
  sleep(2);

  while (1) { // Boucle infinie jusqu'à qu'une équipe soit KO (break)
    //DEBUT DU COMBAT
    combat(&equipeBleue, &equipeRouge, mode, niveau, jauges, vitesses); // Appel de la fonction qui gère le combat 
    sleep(1); // Attente pour mieux voir les tours

    // Vérifiez si une équipe est KO
    if (equipeEstKO(&equipeBleue)) {
      printf("%sBRAVOOOOOO%s 🎉🎉 \n",VIOLET, RESET);
      printf("%sL'équipe bleue%s est KO ! %sL'équipe rouge%s gagne !!!\n",BLEU, RESET, ROUGE, RESET); // Rouge gagne 
      printf("\n");
      break; //arret du jeu
    }
    if (equipeEstKO(&equipeRouge)) {
      printf("%sBRAVOOOOOO%s\n",VIOLET, RESET);
      printf("%sL'équipe rouge est KO%s ! %sL'équipe bleue gagne%s 🎉 🎉\n",ROUGE, RESET, BLEU, RESET); //Bleu gagne
      printf("\n");
      break;//arret du jeu 
    }
  }

}