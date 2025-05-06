void appliquerDegats(Combattants* cible, int degats) {
    int degatsReels = degats - (*cible).defense;
    if (degatsReels < 0) {
        degatsReels = 0;
    }
    (*cible).points_de_vie_courants -= degatsReels;
    if ((*cible).points_de_vie_courants < 0) {
        (*cible).points_de_vie_courants = 0;
    }
    printf("%s subit %d dégâts (PV restants : %d).\n", (*cible).nom, degatsReels, (*cible).points_de_vie_courants);
}