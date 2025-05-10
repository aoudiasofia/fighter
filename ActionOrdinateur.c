#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <unistd.h>
#include <string.h> // Assurez-vous d'inclure <string.h>

void actionOrdinateur(Combattants* joueurActif, Equipe* equipeOrdi, Equipe* equipeAdverse,int nbAdversaires, Combattants allies[], int niveau, int nbAllies ) {
    int cible = 0;
    Combattants* adversaires = equipeAdverse->membres;

    // Choisir la cible
    if (niveau == 1) {
        cible = rand() % 2;
        printf("L'ordinateur attaque aléatoirement %s.\n", adversaires[cible].nom);
    } else {
        if (adversaires[0].points_de_vie_courants <= adversaires[1].points_de_vie_courants) {
            cible = 0;
        } else {
            cible = 1;
        }
        printf("L'ordinateur attaque %s, qui a le moins de PV. \n", adversaires[cible].nom);
    }

    // Utiliser un objet (1 chance sur 3)
    if ((niveau == 2 || niveau == 3) && equipeOrdi->objetUtilise == 0) {
        int chance = rand() % 3;
        if (chance == 0) {
            printf("L'ordinateur utilise l'objet spécial : %s !\n", equipeOrdi->objet.nom);
            appliquerEffetObjet(equipeOrdi->objet, joueurActif);
            equipeOrdi->objetUtilise = 1;
        }
    }

    // Technique spéciale si disponible ( niveau 3 uniquement)
    if (niveau == 3 && essayerUtiliserTechniqueSpeciale(joueurActif, joueurActif->competencesSpeciales) == 1) {
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
        // Cas Luffy        
        } else if (strcmp(joueurActif->nom, "Luffy") == 0)  { 
            printf("Vous allez utiliser la technique spéciale de 🏴‍☠️ Luffy : Gum Gum Bazooka !\n");
            printf("Luffy attaque avec son poing élastique 👊 !\n");
            //choix de la cible
            if(adversaires[0].points_de_vie_courants < 0 && adversaires[1].points_de_vie_courants > 0){
                printf("%s (PV : %d)\n", adversaires[1].nom, adversaires[1].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[1], joueurActif->competencesSpeciales.valeur);

            } else if(adversaires[1].points_de_vie_courants < 0 && adversaires[0].points_de_vie_courants > 0 ){
                printf("%s (PV : %d)\n", adversaires[0].nom, adversaires[0].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[0], joueurActif->competencesSpeciales.valeur);

            } else if(adversaires[0].points_de_vie_courants <= adversaires[1].points_de_vie_courants){
                printf("%s (PV : %d)\n", adversaires[0].nom, adversaires[0].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[0], joueurActif->competencesSpeciales.valeur);
            } else {
                printf("%s (PV : %d)\n", adversaires[1].nom, adversaires[1].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[1], joueurActif->competencesSpeciales.valeur);
            }
               
        //cas de Elsa
        } else if (strcmp(joueurActif->nom, "Elsa") == 0) {
            printf("Vous allez utiliser la technique spéciale de ❄️👑 Elsa : Soin Gelé !\n");
            printf("Elsa soigne un allié avec un vent de glace !\n");   
            //choix de la cible
            for (int i = 0; i < nbAllies; i++) {
                if (allies[i].points_de_vie_courants > 0) {
                    printf(" %s (PV : %d) va être soigné\n", allies[i].nom, allies[i].points_de_vie_courants);
                    sleep(1);
                    allies[i].points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
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
        } else if  (strcmp(joueurActif->nom, "IronMan") == 0) {
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
                    allies[i].points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
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
    } else{
        // Attaque normale
        printf("L'ordinateur attaque normalement %s.\n", adversaires[cible].nom);
        appliquerDegats(&adversaires[cible], joueurActif->attaque);
    }   
}

        