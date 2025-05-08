
#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"
#include <unistd.h>

void gererTourHumain(Combattants* joueurActif, Combattants adversaires[], int nbAdversaires) {
    int choixAction;
    int choixCible;
    printf("\n");
    printf("=== Tour de %s ===", (*joueurActif).nom);
   

    // Choisir une action
    do {
        printf("Choisissez une action :\n");
        sleep(1);
        printf("1 : Attaque normale\n");
        sleep(1);
        printf("2 : Technique spéciale\n");
        sleep(1);
        printf("Votre choix : ");
        int saisieValide = scanf("%d", &choixAction);
        viderBuffer();

        if (saisieValide != 1 || choixAction < 1 || choixAction > 2) {
            printf("\033[1;31m⚠️ Choix invalide. Veuillez entrer 1 ou 2.\033[0m\n");
            choixAction = 0;
        }
    } while (choixAction < 1 || choixAction > 2);

    // Choisir une cible
    do {
        printf("Choisissez un adversaire à attaquer :\n");
        for (int i = 0; i < nbAdversaires; i++) {
            if (adversaires[i].points_de_vie_courants > 0) {
                printf("%d : %s (PV : %d)\n", i, adversaires[i].nom, adversaires[i].points_de_vie_courants);
                sleep(1);
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

    // Appliquer l'action choisie
    if (choixAction == 1) {
        printf("%s attaque %s avec une attaque normale !\n", (*joueurActif).nom, adversaires[choixCible].nom);
        appliquerDegats(&adversaires[choixCible], (*joueurActif).attaque);
    } else if (choixAction == 2) {
        if (essayerUtiliserTechniqueSpeciale(joueurActif, (*joueurActif).competencesSpeciales)) {
            printf("%s utilise sa technique spéciale sur %s !\n", (*joueurActif).nom, adversaires[choixCible].nom);
            appliquerDegats(&adversaires[choixCible], (*joueurActif).competencesSpeciales.valeur);
        } else {
            printf("\033[1;33m⚠️ Technique spéciale pas encore prête.\033[0m\n");
            printf("%s utilise une attaque normale sur %s.\n", (*joueurActif).nom, adversaires[choixCible].nom);
            appliquerDegats(&adversaires[choixCible], (*joueurActif).attaque);
        }
    }

    // Vérifier si l'adversaire est KO
    if (adversaires[choixCible].points_de_vie_courants <= 0) {
        printf("\033[1;31m💀 %s est KO !\033[0m\n", adversaires[choixCible].nom);
    }
}