
#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <unistd.h>
#include <string.h> 

//ajouter les nouvelles fonctions dans le fichier.h

void afficherOptions() {
    printf("Choisissez une action :\n");
    sleep(1);
    printf("1 : Attaque normale\n");
    sleep(1);
    printf("2 : Technique spéciale\n");
    sleep(1);
}

int choisirAction() {
    int choixAction = 0;
    int saisieValide;

    do {
        afficherOptions();
        printf("Votre choix : ");
        saisieValide = scanf("%d", &choixAction);
        viderBuffer();

        if (saisieValide != 1 || choixAction < 1 || choixAction > 2) {
            printf("\033[1;31m⚠️ Choix invalide. Veuillez entrer 1 ou 2.\033[0m\n");
            choixAction = 0; // Réinitialise pour forcer une nouvelle saisie
        }
    } while (choixAction < 1 || choixAction > 2);

    return choixAction;
}

void gererTourHumain(Combattants* joueurActif, Combattants adversaires[], int nbAdversaires, Combattants allies[], int nbAllies) {
    int choixCible;
    printf("\n");
    printf("=== Tour de %s ===", (*joueurActif).nom);
    printf("\n");

    // Choisir une action
    int choixAction = choisirAction();
    
    // Choisir une cible
    do {
        if (choixAction == 1){
        printf("Choisissez un adversaire à attaquer :\n");
        for (int i = 0; i < nbAdversaires; i++) {
            if (adversaires[i].points_de_vie_courants > 0) {
                printf("%d : %s (PV : %d)\n", i, adversaires[i].nom, adversaires[i].points_de_vie_courants);
                sleep(1);
            }
        }
       
        }
        printf("Votre choix : ");
        int saisieValide = scanf("%d", &choixCible);
        viderBuffer();

        if (saisieValide != 1 || choixCible < 0 || choixCible >= nbAdversaires || adversaires[choixCible].points_de_vie_courants <= 0) {
            printf("\033[1;31m⚠️ Choix invalide. Veuillez choisir un adversaire valide.\033[0m\n");
            choixCible = -1;
        }
    } while (choixCible < 0 || choixCible >= nbAdversaires || adversaires[choixCible].points_de_vie_courants <= 0);
    
    
    if (choixAction == 2) { //techniques spéciales
        if (essayerUtiliserTechniqueSpeciale(joueurActif, (*joueurActif).competencesSpeciales)) {
        // 1er cas : dracaufeu
            if (strcmp(joueurActif->nom, "Dracaufeu") == 0)  {
            printf("Vous allez utiliser la technique spéciale de 🔥🐉 Dracaufeu : Danse flamme 🕺 !\n");
            printf("La propagation du feu brûle tous les ennemis !\n");
                for (int i=0; i<nbAdversaires; i++){
                    if (adversaires[i].points_de_vie_courants > 0) {
                        printf("%s subit des dégâts de feu !\n", adversaires[i].nom);
                        appliquerDegats(&adversaires[i], joueurActif->competencesSpeciales.valeur);
                    }
                }
            }   

        // 2eme cas : Luffy
            } else if (strcmp(joueurActif->nom, "Luffy") == 0)  {
                printf("Vous allez utiliser la technique spéciale de 🏴‍☠️ Luffy : Gum Gum Bazooka !\n");
                printf("Luffy attaque avec son poing élastique 👊 !\n");
                //choix de la cible
                for (int i = 0; i < nbAdversaires; i++) {
                    if (adversaires[i].points_de_vie_courants > 0) {
                        printf("%d : %s (PV : %d)\n", i, adversaires[i].nom, adversaires[i].points_de_vie_courants);
                        sleep(1);
                    }
                }
                printf("Votre choix : ");
                int saisieValide = scanf("%d", &choixCible);
                if (saisieValide != 1) {
                    printf("Entrée invalide.\n");
                    viderBuffer();
                }
                appliquerDegats(&adversaires[choixCible], joueurActif->competencesSpeciales.valeur);

            //cas de Elsa
            } else if (strcmp(joueurActif->nom, "Elsa") == 0) {
                printf("Vous allez utiliser la technique spéciale de ❄️👑 Elsa : Soin Gelé !\n");
                printf("Elsa soigne un allié avec un vent de glace !\n");   
                //choix de la cible
                for (int i = 0; i < nbAllies; i++) {
                    if (allies[i].points_de_vie_courants > 0) {
                        printf(" %s (PV : %d) va être soigné\n", allies[i].nom, allies[i].points_de_vie_courants);
                        sleep(1);
                        allies[i].points_de_vie_courants += 40;
                        if (allies[i].points_de_vie_courants>allies[i].points_de_vie_max){
                            allies[i].points_de_vie_courants = allies[i].points_de_vie_max;
                        }
                    } else {
                        printf("%d : %s (KO)\n", i, allies[i].nom);
                        printf("Vous ne pouvez pas soigner un allié KO !\n");
                        printf("Dommage il fallait être plus attentif !\n");
                    }
                }
            // cas de Iron man
            } else if (strcmp(joueurActif->nom, "ironMan") == 0) {
                printf("Vous allez utiliser la technique spéciale de 🤖 IronMan : Armure 🛡️\n");
                printf("IronMan augmente sa défense\n");
                joueurActif->defense +=  joueurActif->competencesSpeciales.valeur;
                    
            //cas de Yoshi
            } else if (strcmp(joueurActif->nom, "Yoshi") == 0) {
                printf("Vous allez utiliser la technique spéciale de 🦖🍄 Yoshi : Bomb'oeuf\n");
                printf("Yoshi lance des oeufs explosifs a tous ses ennemis\n");
                for (int i=0; i<nbAdversaires; i++){
                    if (adversaires[i].points_de_vie_courants > 0) {
                        printf("%s se prend un oeuf !\n", adversaires[i].nom);
                        appliquerDegats(&adversaires[i], joueurActif->competencesSpeciales.valeur);
                    }
                }

            //cas de Zelda
            } else if (strcmp(joueurActif->nom, "Zelda") == 0) {
                printf("Vous allez utiliser la technique spéciale de 🏹✨ Zelda : Lumière Sacrée\n");
                printf("Zelda invoque la lumière divine qui soigne toute son équipe \n");
                
                    
                for (int i = 0; i < nbAllies; i++) {
                    if (allies[i].points_de_vie_courants > 0) {
                        printf(" %s (PV : %d) va être soigné\n", allies[i].nom, allies[i].points_de_vie_courants);
                        sleep(1);
                        allies[i].points_de_vie_courants += 40;
                        if (allies[i].points_de_vie_courants>allies[i].points_de_vie_max){
                            allies[i].points_de_vie_courants = allies[i].points_de_vie_max;
                        }
                        joueurActif->points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
                    } else {
                        joueurActif->points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
                        printf("%d : %s (KO)\n", i, allies[i].nom);
                        printf("Vous ne pouvez pas soigner un allié KO !\n");
                        printf("Seule toi bénéficie de l'attaque spéciale !\n");
                    }
                }        
    
            }

        } else {
            printf("\033[1;33m⚠️ Technique spéciale pas encore prête.\033[0m\n ");
            choixAction = 1;
        }

    // Appliquer l'action choisie
    if (choixAction == 1) {
        printf("%s attaque %s avec une attaque normale !\n", (*joueurActif).nom, adversaires[choixCible].nom);
        appliquerDegats(&adversaires[choixCible], (*joueurActif).attaque);

    } 
}