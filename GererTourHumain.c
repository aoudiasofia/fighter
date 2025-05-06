void gererTourHumain(Combattants* joueurActif, Combattants adversaires[], int nbAdversaires) {
    int choixAction;
    int choixCible;

    printf("C'est au tour de %s de jouer.\n", (*joueurActif).nom);

    // Choisir une action
    do {
        printf("Choisissez une action :\n");
        printf("1 : Attaque normale\n");
        printf("2 : Technique spéciale\n");
        printf("Votre choix : ");
        scanf("%d", &choixAction);

        if (choixAction < 1 || choixAction > 2) {
            printf("⚠️ Choix invalide. Veuillez entrer 1 ou 2.\n"); //AJOUTER GESTION SI AUTRE CARACTERES QUE 1 OU 2
        }
    } while (choixAction < 1 || choixAction > 2);

    // Choisir une cible
    do {
        printf("Choisissez un adversaire à attaquer :\n");
        for (int i = 0; i < nbAdversaires; i++) {
            if (adversaires[i].points_de_vie_courants > 0) {
                printf("%d : %s (PV : %d)\n", i, adversaires[i].nom, adversaires[i].points_de_vie_courants);
            }
        }
        printf("Votre choix : ");
        scanf("%d", &choixCible);

        if (choixCible < 0 || choixCible >= nbAdversaires || adversaires[choixCible].points_de_vie_courants <= 0) {
            printf("⚠️ Choix invalide. Veuillez choisir un adversaire valide.\n"); //AJOUTER GESTION SI AUTRE CARACTERES 
        }
    } while (choixCible < 0 || choixCible >= nbAdversaires || adversaires[choixCible].points_de_vie_courants <= 0);

    // Appliquer l'action
    if (choixAction == 1) {
        printf("%s attaque %s avec une attaque normale !\n", (*joueurActif).nom, adversaires[choixCible].nom);
        appliquerDegats(&adversaires[choixCible], (*joueurActif).attaque); //foncion à terminer 
    } else if (choixAction == 2) {
        if ((*joueurActif).competencesSpeciales.nbToursRecharge == 0) {
            printf("%s utilise sa technique spéciale sur %s !\n", (*joueurActif).nom, adversaires[choixCible].nom);
            appliquerDegats(&adversaires[choixCible], (*joueurActif).competencesSpeciales.degats);
            (*joueurActif).competencesSpeciales.nbToursRecharge = (*joueurActif).competencesSpeciales.recharge;
        } else {
            printf("⚠️ Technique spéciale non disponible. Une attaque normale est utilisée à la place.\n");
            appliquerDegats(&adversaires[choixCible], (*joueurActif).attaque);
        }
    }

    // Vérifier si l'adversaire est KO
    if (adversaires[choixCible].points_de_vie_courants <= 0) {
        printf("%s est KO !\n", adversaires[choixCible].nom);
    }
}