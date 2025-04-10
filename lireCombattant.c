
int lireCombattants(Combattants tab[], TechniqueSpeciale tabTech[], const char* nomFichier) {
    FILE* f = fopen(nomFichier, "r");

    if (f == NULL) {
        printf("Erreur d'ouverture du fichier %s\n", nomFichier);
        return -1;
    }

    int i = 0;
    int indexTech;
    char nom[50];
    while (fscanf(f, "%49s %d %d %d %d %d %d",
                  nom,
                  &tab[i].points_de_vie_courants,
                  &tab[i].points_de_vie_max,
                  &tab[i].attaque,
                  &tab[i].defense,
                  &tab[i].vitesse,
                  &indexTech) == 7) {

        strcpy(tab[i].competencesSpeciales.nom, tabTech[indexTech].nom);
        tab[i].competencesSpeciales.valeur = tabTech[indexTech].valeur;
        strcpy(tab[i].competencesSpeciales.description, tabTech[indexTech].description);
        tab[i].competencesSpeciales.nbToursActifs = tabTech[indexTech].nbToursActifs;
        tab[i].competencesSpeciales.nbToursRecharge = tabTech[indexTech].nbToursRecharge;
        tab[i].competencesSpeciales.operation = tabTech[indexTech].operation;

        i++;
    }

    fclose(f);
    return i;
}