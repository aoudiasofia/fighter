#include "fichier.h"



int lireTechniques(TechniqueSpeciale* techniques, const char* nomFichier) {
    FILE* f = fopen(nomFichier, "r");

    if (f == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return -1;
    }

    int i = 0;
    while (fscanf(f, " \"%49[^\"]\" %f \"%199[^\"]\" %d %d %d",
        techniques[i].nom,
        &techniques[i].valeur,
        techniques[i].description,
        &techniques[i].nbToursActifs,
        &techniques[i].nbToursRecharge,
        (int*)&techniques[i].operation) == 6) { // 6 vérifie que fscanf a bien lu les 6 valeurs attendues dans la ligne.
i++;
}
fclose(f);
    return i; // nombre de techniques lues
}

