# fighter
# CY-FIGHTERS 🥊

Bienvenue dans **CY-FIGHTERS**, un jeu de combat stratégique où deux équipes s'affrontent pour la victoire ultime ! 🎮

---

## 🚀 Fonctionnalités

- **Modes de jeu** :
  - Mode 2 joueurs : Affrontez un ami en duel.
  - Mode 1 joueur : Défiez l'ordinateur.
- **Système de combat** :
  - Chaque joueur choisit 2 combattants avec des compétences uniques.
  - Les jauges de vitesse déterminent l'ordre des tours.
  - Utilisez des attaques normales ou des techniques spéciales pour vaincre vos adversaires.
- **Objets bonus mystères 🎁** :
  - Chaque équipe dispose d'un objet bonus pour renverser le cours du combat.
- **Animations immersives** :
  - Interface colorée et dynamique pour une meilleure expérience utilisateur.

---

## 📂 Structure du projet

### Fichiers principaux :
- **`Equipe.c`** : Gestion des équipes, choix des modes de jeu et lancement du combat.
- **`CombattantJouer.c`** : Gestion des jauges et détermination du combattant prêt à jouer.
- **`appliquerDegats.c`** : Calcul des dégâts infligés aux combattants.
- **`affichage.c`** : Affichage des informations et des actions disponibles.
- **`ActionOrdinateur.c`** : Logique des actions de l'ordinateur.
- **`fichier.h`** : Définitions des structures et des constantes globales.

### Fichiers de données :
- **`TechniquesSpeciales.txt`** : Liste des techniques spéciales disponibles.
- **`Combattants.txt`** : Liste des combattants avec leurs statistiques.

---

## 🛠️ Installation et exécution

### Prérequis
- Un compilateur C (comme `gcc`).
- Un terminal compatible avec les séquences ANSI pour les couleurs et animations.

### Étapes

#### Avec `make` (recommandé) :

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/aoudiasofia/fighter
   cd fighter

2. Compilez le projet :
   Avec : `make`
    

#### Sans `make` :
1. Clonez le dépôt :
   ```bash
   git clone https://github.com/aoudiasofia/fighter
   cd fighter

2. Compilez le projet avec gcc :
   gcc -Wall -o CYFighter quipe.c lectureCombattants.c variables.c lectureTechniques.c genererObjet.c afficheObjet.c ActionOrdinateur.c combat.c appliquerDegats.c appliquerEffetObjet.c CombattantJouer.c GererTourHumain.c essayerTechSpe.c equipeKo.c affichage.c -lm

3. Lancez le jeu :
    ./CYFighter

🎮 Comment jouer ?

1. Choisissez un mode de jeu :
    Mode 1 : 2 joueurs.
    Mode 2 : 1 joueur contre l'ordinateur.

2. Sélectionnez vos combattants :
    Chaque joueur choisit 2 combattants parmi une liste.

3. Combattez ! :

    Utilisez des attaques normales ou des techniques spéciales.
    Exploitez les objets bonus pour prendre l'avantage.

3. Gagnez :
    Mettez l'équipe adverse K.O. pour remporter la victoire.


📜 Règles du jeu
Chaque joueur choisit 2 combattants.
Chaque équipe dispose d'un objet bonus mystère.
Les jauges de vitesse déterminent l'ordre des tours.
Le but : mettre l'équipe adverse K.O.
