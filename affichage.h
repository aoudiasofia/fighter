#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "fichier.h" // test

void afficherEquipe(Equipe equipe, char* couleurEquipe);
void afficherEtatCombat(Equipe bleue, Equipe rouge);
void afficherTourJoueur(Combattants* joueur, Equipe* equipe);
void afficherActionsPossibles(Combattants* joueur, Equipe* equipe);
void afficherBarreDeVie(int pv, int pvMax);

#endif