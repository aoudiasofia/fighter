
void actionOrdinateur(Combattants* joueurActif, Equipe* equipeOrdi, Equipe* equipeAdverse, int niveau) {
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
        printf("L'ordinateur attaque %s, qui a le moins de PV.\n", adversaires[cible].nom);
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

    // Technique spéciale si disponible (niveau 3 uniquement)
    if (niveau == 3 && essayerUtiliserTechniqueSpeciale(joueurActif, joueurActif->competencesSpeciales) == 1) {
        printf("L'ordinateur utilise sa technique spéciale contre %s !\n", adversaires[cible].nom);
        appliquerDegats(&adversaires[cible], joueurActif->competencesSpeciales.valeur);
    } else {
        // Attaque normale
        printf("L'ordinateur attaque normalement %s.\n", adversaires[cible].nom);
        appliquerDegats(&adversaires[cible], joueurActif->attaque);
    }
}