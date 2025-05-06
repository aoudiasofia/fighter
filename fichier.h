

#ifndef FICHIER_H
#define FICHIER_H
#define NBCOMBATTANTS 6




//TECHNIQUES SPECIALES
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

//strucutre combattants
typedef struct {
    char nom[50];
    int points_de_vie_courants;
    int points_de_vie_max;
    int attaque;
    int defense;
    int agilite; // sur 10
    int vitesse;
    TechniqueSpeciale competencesSpeciales;
} Combattants;

//OBJETS ALEATOIRES
typedef enum {
    BOUCLIER,
    POTION,
    TROLL
} ObjetType;

typedef struct {
    ObjetType type;
    char nom[20];
    char description[100];
} Objet;

//STRUCTURE EQUIPE ( COMBATTATS + OBJET )

#define NBEQUIPES 2

typedef struct {
    char nom[50];
    Combattants membres[NBEQUIPES];
    Objet objet;
} Equipe;


extern char* nomsCombattants[NBCOMBATTANTS];
extern Combattants tab[NBCOMBATTANTS];

int lectureTechniques(TechniqueSpeciale* techniques, const char* nomFichier);
int lectureCombattants(Combattants* tab, TechniqueSpeciale* tabTech, const char* nomFichier);

Objet genererObjetAleatoire();
void afficherObjet(Objet objet);
void afficherChargement();
void viderBuffer();

#endif