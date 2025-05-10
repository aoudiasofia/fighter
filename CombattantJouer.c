#define COEF 10.0
#define MAX_JAUGE 90.0

int choisirCombattantAJouer(float jauges[], int vitesses[], int nbCombattants) {
    int index = -1;
    float maxJauge = 0.0;

    // Mise à jour des jauges
    for (int i = 0; i < nbCombattants; i++) {
        if (vitesses[i] > 0) { // Vérifie que la vitesse est positive
            jauges[i] += vitesses[i] * COEF / 10.0;
            if (jauges[i] > MAX_JAUGE) {
                jauges[i] = MAX_JAUGE; // Limite la jauge à MAX_JAUGE
            }
        }
    }

    // Trouver le joueur prêt à jouer
    for (int i = 0; i < nbCombattants; i++) {
        if (jauges[i] >= MAX_JAUGE && jauges[i] > maxJauge) {
            maxJauge = jauges[i];
            index = i;
        }
    }

    // Remise à zéro ou conservation de l'excès
    if (index != -1) {
        jauges[index] -= MAX_JAUGE; // Conserve l'excès de jauge
    }

    return index;
}