 //fonction vitesse qui va choisir le combattant qui va jouer
//le joueur qui joue est celui qui a la plus grande jauge
//la jauge est calculée en fonction de la vitesse du combattant
//la jauge est remise à zéro quand le combattant joue
// UN JOUEUR VA DONC OMMENCER A JOUER 
// soit le joueur et l'ordinateur soit le joueur est un humain 


// cas le joueur et u  humain 

//actionOrdinateur(Combattants equipeBleue[], Combattants equipeRouge[], int niveau);


// cas le joueur est un humain

// demander qu joueur qui il veut attaquer

// demander si il veut utiliser une technique spéciale
// si oui verifier qu'on peut utiliser la technique spéciale
// sinon utiliser une attaque normale
//on fait perdre des PV 
// on verifie que aucune esuipe n'a plus de PV
// si une equipe n'a plus de PV on affiche que l'equipe a gagné

void combat(Equipe* bleue, Equipe* rouge, int mode, int niveauIA) {
    // Initialiser les jauges de vitesse des 4 combattants (2 par équipe)
    // Boucle tant qu'une des deux équipes n'est pas morte
        // Avancer les jauges en fonction de la vitesse
        // Trouver qui joue (celui dont la jauge atteint 100)
        // Si joueur humain :
            // Proposer attaque normale ou spéciale (si dispo)
            // Choisir la cible
        // Si ordi :
            // Choisir action selon le niveau
        // Appliquer dégâts
        // Vérifier si un combattant est KO
        // Réinitialiser jauge du combattant qui a joué
}
