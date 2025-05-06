void actionOrdinateur(Combattants equipeBleue[], Combattants equipeRouge[], int niveau) {
    int cible = 0;

    // Trouver la cible en fonction du niveau
    if (niveau == 1) {
        // Niveau Noob : cible aléatoire
        cible = rand() % 2;
        printf("L'ordinateur attaque aléatoirement %s.\n", equipeBleue[cible].nom);
    } else if (niveau == 2 || niveau == 3) {
        // Niveau Facile ou Moyen : cible avec le moins de PV
        if (equipeBleue[0].points_de_vie_courants <= equipeBleue[1].points_de_vie_courants) {
            cible = 0;
        } else {
            cible = 1;
        }
        printf("L'ordinateur attaque %s, qui a le moins de PV.\n", equipeBleue[cible].nom);
    }

// Gestion de l'objet (Facile et Moyen uniquement)
    if ((niveau == 2 || niveau == 3) && !equipeRouge[0].objet_utilise) {
        int chance = rand() % 3; // Génère un nombre entre 0 et 2
        if (chance == 0) { // 1 chance sur 3
            appliquerEffetObjet(objet, &cible);// inventer une fonction qu'il faudrait écrire
            
            equipeRouge[0].objet_utilise = 1; // Marque l'objet comme utilisé
        }
    }

    // Vérifier si la technique spéciale est disponible (niveau Moyen uniquement)
    if (niveau == 3 && equipeRouge[0].techniqueSpeciales.disponible) { // renommer
        // Utiliser la technique spéciale
        printf("L'ordinateur utilise sa technique spéciale contre %s !\n", equipeBleue[cible].nom);
        equipeBleue[cible].points_de_vie_courants -= equipeRouge[0].techniqueSpeciales.degats;// renommer
        equipeRouge[0].techniqueSpeciales.disponible = 0; // renommer
// Technique utilisée
    } else {
        // Sinon, effectuer une attaque normale
        equipeBleue[cible].points_de_vie_courants -= equipeRouge[0].attaque;
    }
}