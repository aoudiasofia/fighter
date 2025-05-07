void afficherBarreVie(int pvActuels, int pvMax) {
    int longueurBarre = 20;  // Longueur totale de la barre
    int nbCaractères = (pvActuels * longueurBarre) / pvMax;

    printf("[");
    for (int i = 0; i < longueurBarre; i++) {
        if (i < nbCaractères) {
            // Couleur verte pour PV restants
            printf("\033[1;32m#\033[0m"); 
        } else {
    
            printf(" ");
        }
    }
    printf("] %d/%d PV\n", pvActuels, pvMax);
}




void afficherEtatEquipes(Equipe* bleue, Equipe* rouge) {
    printf("\n\033[1;34m=== ÉQUIPE BLEUE ===\033[0m            \033[1;31m=== ÉQUIPE ROUGE ===\033[0m\n");

    for (int i = 0; i < 2; i++) {
        afficherCombattant(bleue->membres[i], "\033[1;34m");
        printf("     ");  // Espace entre les deux équipes
        afficherCombattant(rouge->membres[i], "\033[1;31m");
        printf("\n");
    }

    printf("--------------------------------------------------------------\n");
}