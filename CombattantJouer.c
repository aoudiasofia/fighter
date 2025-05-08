#define COEF 5.0
#define MAX_JAUGE 10.0

int choisirCombattantAJouer(float jauges[], int vitesses[], int nbCombattants) { //tableau avec vitesse de chaque combattants 
    int index = -1;
    float maxJauge = 0;

    //  mise à jour des jauges
    for (int i = 0; i < nbCombattants; i++) {
        jauges[i] += vitesses[i] * COEF / 10.0;
    }

    // trouver le joueur prêt à jouer
    for (int i = 0; i < nbCombattants; i++) {
        if (jauges[i] >= MAX_JAUGE && jauges[i] > maxJauge) {
            maxJauge = jauges[i];
            index = i;
        }
    }

    // remise à zéro
    if (index != -1) {
        jauges[index] = 0;
    }

    return index;
}