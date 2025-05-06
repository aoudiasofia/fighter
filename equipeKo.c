int equipeEstKO(Equipe eq) {
    for (int i = 0; i < 2; i++) { // Supposons que chaque équipe a 2 membres
        if (eq.membres[i].points_de_vie_courants > 0) {
            return 0; // L'équipe n'est pas éliminée
        }
    }
    return 1; // Tous les membres de l'équipe sont KO
}


// utilisation de la fonction
//if (equipeEstKO(equipeBleue)) {
//  printf("L'équipe bleue est éliminée !\n");
//} else {
 //   printf("L'équipe bleue est toujours en jeu.\n");
//}