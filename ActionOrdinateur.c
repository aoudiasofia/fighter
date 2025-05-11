#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <unistd.h>
#include <string.h> 


//fonctions modélisant le tour de l'ordinateur
void actionOrdinateur(Combattants* joueurActif, Equipe* equipeOrdi, Equipe* equipeAdverse,int nbAdversaires, Combattants allies[], int niveau, int nbAllies ) {
    int cible = 0;
    Combattants* adversaires = equipeAdverse->membres;

    // Choisir la cible
    if (niveau == 1) {
        cible = rand() % 2; //niveau 1 : attaque aléatoire
        printf("L'ordinateur attaque aléatoirement %s.\n", adversaires[cible].nom);
    } else { //pour niveau 2 et 3 : le plus faible est attaqué
        if ((adversaires[0].points_de_vie_courants <= adversaires[1].points_de_vie_courants)) { //si combattant a moins de Pv que le 2
           if (adversaires[0].points_de_vie_courants>0){ //on verifie que le combattant n'est pas KO
                cible = 0;
           } else {
                cible = 1; // si le 1 est KO, on attaque le 2
           }
        } else if (adversaires[1].points_de_vie_courants <= adversaires[0].points_de_vie_courants ) { //si combattant 2 a moins de Pv que le 1
            if (adversaires[1].points_de_vie_courants>0){ //on verifie que le combattant n'est pas KO
                cible = 1;
            } else {
                cible = 0;// si le 2 est KO, on attaque le 1
            }
        }
        printf("L'ordinateur attaque %s, qui a le moins de PV. \n", adversaires[cible].nom);
    }

    // Utiliser un objet (1 chance sur 3)
    if ((niveau == 2 || niveau == 3) && equipeOrdi->objetUtilise == 0) { // pas d'objet si niveau 1
        int chance = rand() % 3;
        if (chance == 0) {
            printf("L'ordinateur utilise l'objet spécial : %s !\n", equipeOrdi->objet.nom);
            sleep(1);
            appliquerEffetObjet(equipeOrdi->objet, joueurActif);
            equipeOrdi->objetUtilise = 1;
        }
    }

    // Technique spéciale si disponible ( niveau 3 uniquement)
    if (niveau == 3 && joueurActif != NULL && essayerUtiliserTechniqueSpeciale(joueurActif) == 1) {
        
        if (strcmp(joueurActif->nom, "Dracaufeu") == 0) { // 1er cas : dracaufeu
            joueurActif->competencesSpeciales.jauge = 0; // reset du compteur
            printf("L'ordinateur utilise la technique spéciale de 🔥 Dracaufeu 🐉 : Danse flamme 🕺 !\n");
            printf("La propagation du feu brûle tous les ennemis !\n");
            sleep(1);
            for (int i=0; i<nbAdversaires; i++){
                if (adversaires[i].points_de_vie_courants > 0) { // on verifie que le combattant n'est pas KO
                    printf("%s subit des dégâts de feu !\n", adversaires[i].nom);
                    appliquerDegats(&adversaires[i], joueurActif->competencesSpeciales.valeur);
                    for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                        if (allies[i].points_de_vie_courants > 0) {
                            allies[i].competencesSpeciales.jauge ++; 
                        }    
                    }
                    for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                        if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                            equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                        }    
                    }
                    joueurActif->competencesSpeciales.jauge ++; // incrémentation
                }
            }
               
        } else if (strcmp(joueurActif->nom, "Luffy") == 0)  { // Cas Luffy 
            joueurActif->competencesSpeciales.jauge = 0; // reset du compteur
            printf("L'ordinateur utilise la technique spéciale de 🏴‍☠️ Luffy : Gum Gum Bazooka !\n");
            printf("Luffy attaque avec son poing élastique 👊 !\n");
            sleep(1);
            //choix de la cible
            if(adversaires[0].points_de_vie_courants < 0 && adversaires[1].points_de_vie_courants > 0){ //on verifie pas KO
                printf("%s (PV : %d)\n", adversaires[1].nom, adversaires[1].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[1], joueurActif->competencesSpeciales.valeur);
                for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                    if (allies[i].points_de_vie_courants > 0) {
                        allies[i].competencesSpeciales.jauge ++; 
                    }    
                }
                for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                    if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                        equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                    }    
                }
                joueurActif->competencesSpeciales.jauge ++; // incrémentation

            } else if(adversaires[1].points_de_vie_courants < 0 && adversaires[0].points_de_vie_courants > 0 ){
                printf("%s (PV : %d)\n", adversaires[0].nom, adversaires[0].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[0], joueurActif->competencesSpeciales.valeur);
                for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                    if (allies[i].points_de_vie_courants > 0) {
                        allies[i].competencesSpeciales.jauge ++; 
                    }    
                }
                for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                    if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                        equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                    }    
                }
                joueurActif->competencesSpeciales.jauge ++; // incrémentation

            } else if(adversaires[0].points_de_vie_courants <= adversaires[1].points_de_vie_courants){ 
                printf("%s (PV : %d)\n", adversaires[0].nom, adversaires[0].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[0], joueurActif->competencesSpeciales.valeur);
                for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                    if (allies[i].points_de_vie_courants > 0) {
                        allies[i].competencesSpeciales.jauge ++; 
                    }    
                }
                for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                    if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                        equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                    }    
                }
                joueurActif->competencesSpeciales.jauge ++; // incrémentation
            } else {
                printf("%s (PV : %d)\n", adversaires[1].nom, adversaires[1].points_de_vie_courants);
                sleep(1);
                appliquerDegats(&adversaires[1], joueurActif->competencesSpeciales.valeur);
                for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                    if (allies[i].points_de_vie_courants > 0) {
                        allies[i].competencesSpeciales.jauge ++; 
                    }    
                }
                for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                    if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                        equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                    }    
                }
                joueurActif->competencesSpeciales.jauge ++; // incrémentation
            }
               
        
        } else if (strcmp(joueurActif->nom, "Elsa") == 0) {  //cas de Elsa
            joueurActif->competencesSpeciales.jauge = 0; // reset du compteur
            printf("L'ordinateur utilise la technique spéciale de ❄️ Elsa : Soin Gelé !\n");
            printf("Elsa soigne son équipe avec un vent de glace !\n");   
            sleep(1);
            //choix de la cible
            for (int i = 0; i < nbAllies; i++) {
                if (allies[i].points_de_vie_courants > 0) {
                    printf(" %s (PV : %d) va être soigné\n", allies[i].nom, allies[i].points_de_vie_courants);
                    sleep(1);
                    allies[i].points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
                    if (allies[i].points_de_vie_courants>allies[i].points_de_vie_max){ // on verifie si les points de vie ne dépassent pas le max
                        allies[i].points_de_vie_courants = allies[i].points_de_vie_max;
                    }
                } else {
                    printf("%d : %s (KO)\n", i, allies[i].nom);
                    printf("Elsa ne peut pas soigner un allié KO !\n");
                }
            }
            for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                if (allies[i].points_de_vie_courants > 0) {
                    allies[i].competencesSpeciales.jauge ++; 
                }    
            }
            for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                    equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                }    
            }
            joueurActif->competencesSpeciales.jauge ++; // incrémentation

        } else if  (strcmp(joueurActif->nom, "IronMan") == 0) {  // cas de Iron man
            joueurActif->competencesSpeciales.jauge = 0; // reset du compteur
            printf("L'ordinateur utilise la technique spéciale de 🤖 IronMan : Armure 🛡️\n");
            printf("IronMan augmente sa défense\n");
            sleep(1);
            joueurActif->defense +=  joueurActif->competencesSpeciales.valeur;

            for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                if (allies[i].points_de_vie_courants > 0) {
                    allies[i].competencesSpeciales.jauge ++; 
                }    
            }
            for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                    equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                }    
            }
            joueurActif->competencesSpeciales.jauge ++; // incrémentation

        } else if (strcmp(joueurActif->nom, "Yoshi") == 0) {  //cas de Yoshi
            joueurActif->competencesSpeciales.jauge = 0; // reset du compteur
            printf("L'ordinateur utilise la technique spéciale de 🦖🍄 Yoshi : Bomb'oeuf\n");
            printf("Yoshi lance des oeufs explosifs a tous ses ennemis\n");
            sleep(1);
            for (int i=0; i<nbAdversaires; i++){
                if (adversaires[i].points_de_vie_courants > 0) {
                    printf("%s se prend un oeuf !\n", adversaires[i].nom);
                    appliquerDegats(&adversaires[i], joueurActif->competencesSpeciales.valeur);

                    for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                        if (allies[i].points_de_vie_courants > 0) {
                            allies[i].competencesSpeciales.jauge ++; 
                        }    
                    }
                    for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                        if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                            equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                        }    
                    }
                    joueurActif->competencesSpeciales.jauge ++; // incrémentation
                }
            }

        } else if (strcmp(joueurActif->nom, "Zelda") == 0) {  //cas de Zelda
            joueurActif->competencesSpeciales.jauge = 0; // reset du compteur
            printf("L'ordinateur utilise la technique spéciale de 🏹✨ Zelda : Lumière Sacrée\n");
            printf("Zelda invoque la lumière divine qui soigne toute son équipe \n");
            sleep(1);
            for (int i = 0; i < nbAllies; i++) { //pour toute l'équipe de Zela 
                if (allies[i].points_de_vie_courants > 0) {
                    printf(" %s (PV : %d) va être soigné\n", allies[i].nom, allies[i].points_de_vie_courants);
                    sleep(1);
                    allies[i].points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
                    if (allies[i].points_de_vie_courants>allies[i].points_de_vie_max){ // on verifie si les points de vie ne dépassent pas le max
                        allies[i].points_de_vie_courants = allies[i].points_de_vie_max;
                    }
                    joueurActif->points_de_vie_courants += joueurActif->competencesSpeciales.valeur; // augmente les points de vie 
                    if(joueurActif->points_de_vie_courants > joueurActif->points_de_vie_max){   // on verifie si les points de vie ne dépassent pas le max
                        joueurActif->points_de_vie_courants = joueurActif->points_de_vie_max;
                    }
                } else {
                    joueurActif->points_de_vie_courants += joueurActif->competencesSpeciales.valeur;
                    printf("%d : %s (KO)\n", i, allies[i].nom);
                    printf("Vous ne pouvez pas soigner un allié KO !\n");
                    printf("Seule toi bénéficie de l'attaque spéciale !\n");
                }
            }        
            for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
                if (allies[i].points_de_vie_courants > 0) {
                    allies[i].competencesSpeciales.jauge ++; 
                }    
            }
            for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
                if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                    equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
                }    
            }
            joueurActif->competencesSpeciales.jauge ++; // incrémentation

        } 
    } else {
        // Attaque normale
        printf("L'ordinateur attaque normalement %s !\n", equipeAdverse[cible].nom);
        appliquerDegats(&adversaires[cible], joueurActif->attaque);
        for (int i=0; i<nbAllies; i++){ // on incrémente la jauge de tous les alliés
            if (allies[i].points_de_vie_courants > 0) {
                allies[i].competencesSpeciales.jauge ++; 
            }    
        }
        for (int i=0; i<nbAdversaires; i++){ // on incrémente la jauge de tous les adversaires
            if (equipeAdverse->membres[i].points_de_vie_courants > 0) {
                equipeAdverse->membres[i].competencesSpeciales.jauge ++; 
            }    
        }
        joueurActif->competencesSpeciales.jauge ++; // incrémentation
    }

}

        