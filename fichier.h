

#ifndef FICHIER_H
#define FICHIER_H
#define NBCOMBATTANTS 6




//TECHNIQUES SPECIALES

typedef struct {
    char nom[50];
    float valeur;
    char description[200];
    int nbToursRecharge;
    int nbToursActif;
    int jauge;
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
    int objetUtilise; // 0 si pas utilisé, 1 si utilisé
} Equipe;


extern char* nomsCombattants[NBCOMBATTANTS];
extern Combattants tab[NBCOMBATTANTS];

int lectureTechniques(TechniqueSpeciale* techniques, const char* nomFichier);
int lectureCombattants(Combattants* tab, TechniqueSpeciale* tabTech, const char* nomFichier);

Objet genererObjetAleatoire();
void afficherObjet(Objet objet);
void afficherChargement();
void viderBuffer();
void actionOrdinateur(Combattants* joueurActif, Equipe* equipeOrdi, Equipe* equipeAdverse,int nbAdversaires, Combattants allies[], int niveau, int nbAllies );
void appliquerDegats(Combattants* cible, int degats);
void appliquerEffetObjet(Objet objet, Combattants* cible) ;
int peutUtiliserObjet(Objet objet, Equipe* eq);
void utiliserObjet(Equipe* eq, Combattants* utilisateur);
int choisirCombattantAJouer(float jauges[], int vitesses[], int nbCombattants);
void combat(Equipe* bleue, Equipe* rouge, int mode, int niveauOrdinateur, float* jauges, int* vitesses);
int equipeEstKO(Equipe* eq);
void gererTourHumain(Combattants* joueurActif, Combattants adversaires[], int nbAdversaires, Combattants allies[], int nbAllies);
int essayerUtiliserTechniqueSpeciale(Combattants* joueur);
void afficherOptions();
int choisirAction();
#endif