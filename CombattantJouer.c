#define COEF 10.0
#define MAX_JAUGE 90.0

int choisirCombattantAJouer(float jauges[], int vitesses[], int nbCombattants) {
    int index = -1;
    float jauge_inter = 0.0;

    // Mise à jour des jauges
    for (int i = 0; i < nbCombattants; i++) {
        if (vitesses[i] > 0) { // Vérifie que la vitesse est positive
            jauges[i] += vitesses[i] * COEF / 10.0;
            if (jauges[i] >= MAX_JAUGE && jauges[i] > jauge_inter) { // Trouver le joueur prêt à jouer
                jauge_inter = jauges[i]; //mise à jour de la jauge intermédiaire
                index = i;
            }
        }
    }

    // Remise à zéro de la jauge 
    if (index != -1) {
        jauges[index] = 0;
    }

    return index;
}