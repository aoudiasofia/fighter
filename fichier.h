

#ifndef FICHIER_H
#define FICHIER_H
#define NBCOMBATTANTS 6

typedef enum {
    addition,
    soustraction,
    multiplication,
    division
} Operation;

typedef struct {
    char nom[50];
    float valeur;
    char description[200];
    int nbToursActifs;
    int nbToursRecharge;
    Operation operation;
} TechniqueSpeciale;

typedef struct {
    int points_de_vie_courants;
    int points_de_vie_max;
    int attaque;
    int defense;
    int agilite; // sur 10
    int vitesse;
    TechniqueSpeciale competencesSpeciales;
} Combattants;

extern char* nomsCombattants[NBCOMBATTANTS];
extern Combattants tab[NBCOMBATTANTS];

int lectureTechniques(TechniqueSpeciale* techniques, const char* nomFichier);
int lectureCombattants(Combattants* tab, TechniqueSpeciale* tabTech, const char* nomFichier);

#endif