

//bibliotheque 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//énumération des opérations
typedef enum{
    addition,
    soustraction,
    multiplication,
    divison
} Operation;


 //structure technique spéciales
typedef struct {
    char nom[50];                     
    float valeur;                      // Valeur ( +30% de vitesse, -20% de défense)
    char description[200];            // Description 
    int nbToursActifs;                // 0 si instantané
    int nbToursRecharge;              // temps de recharge ( en nombre de tours)
    Operation operation;              // type d'opération 
} TechniqueSpeciale;


//structure pour les personnages 
typedef struct{
    int points_de_vie_courants; //verifier si négatifs ou nuls, si KO ne peut plus participer jusqu'à la fin du combat 
    int points_de_vie_max;  //limite en cas de soins
    int attaque; //dégats de base infliger
    int defense; //calcul pourcentage de réduction de dégats 
    int vitesse; // pourcentage chances pour éviter un attaque
    TechniqueSpeciale competencesSpeciales; 
} Combattants;


