#include <stdio.h>
#include "affichage.h"
#include "couleurs.h"
#include "fichier.h"
#include <unistd.h>

// Affiche les infos d'une équipe
void afficherEquipe(Equipe equipe, char* couleurEquipe) {
    printf("============================================\n");
    printf(" %sEQUIPE : %s\n", couleurEquipe, RESET);
    sleep(1);
    for (int i = 0; i < NBEQUIPES; i++) {
        printf("Nom : %s | ❤️ PV : %d/%d | ⚔️ ATQ : %d | 🛡️ DEF : %d | ⚡ VIT : %d | 🥷 Agilité : %d | Compétence : %s\n",
            equipe.membres[i].nom,
            equipe.membres[i].points_de_vie_courants,
            equipe.membres[i].points_de_vie_max,
            equipe.membres[i].attaque,
            equipe.membres[i].defense,
            equipe.membres[i].vitesse,
            equipe.membres[i].agilite,
            equipe.membres[i].competencesSpeciales.nom);
    
    }
    printf("============================================\n");
    sleep(1);
}

// Affiche l'état complet de chaque équipe
void afficherEtatCombat(Equipe bleue, Equipe rouge) {
    afficherEquipe(bleue, BLEU);
    afficherEquipe(rouge, ROUGE);
}

// Affiche le début du tour d'un joueur
void afficherTourJoueur(Combattants* joueur, Equipe* equipe) {
    printf("\n✨ C'est au tour de %s\n", joueur->nom);
    sleep(1);
    printf("❤️ PV : ");
    afficherBarreDeVie(joueur->points_de_vie_courants, joueur->points_de_vie_max);
    printf("\n");
}

// Affiche les actions possibles pour le joueur actif
void afficherActionsPossibles(Combattants* joueur, Equipe* equipe) {
    printf("\n");
    printf("Actions :\n");
    sleep(1);
    printf("1️⃣  Attaquer un adversaire\n");
    sleep(1);
    if (joueur != NULL && essayerUtiliserTechniqueSpeciale(joueur)) { // Vérifie si la technique spéciale est disponible
        printf("  Technique spéciale de %s : (Rechargée : %d / %d tours)\n", 
        joueur->nom, joueur->competencesSpeciales.jauge, joueur->competencesSpeciales.nbToursRecharge);
        printf("2️⃣  Utiliser la technique spéciale \"%s\" (%s)\n", joueur->competencesSpeciales.nom, joueur->competencesSpeciales.description);
        sleep(1);
    } else {
        printf("⛔ Technique spéciale pas encore disponible \n");
        sleep(1);
    }
    if (equipe->objetUtilise == 0) { // Vérifie si l'objet n'a pas été utilisé
        printf("3️⃣  Utiliser l'objet bonus %s : %s\n", equipe->objet.nom, equipe->objet.description);
        sleep(1);
    } else {
        printf("⛔ Objet déjà utilisé \n");
        sleep(1);
    }
    printf("\n");
}

// Affiche une barre de vie textuelle
void afficherBarreDeVie(int pv, int pvMax) {
    int total = 20;
    int nbBlocs = (pv * total) / pvMax;
    printf("[");
    for (int i = 0; i < total; i++) {
        if (i < nbBlocs)
            printf("█"); 
        else
            printf(" ");
    }
    printf("] %d/%d", pv, pvMax);
}