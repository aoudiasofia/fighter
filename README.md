# fighter
# CY-FIGHTERS 🥊

Bienvenue dans **CY-FIGHTERS**, un jeu de combat où deux équipes s'affrontent pour la victoire ultime ! 🎮

---
## 🤝 Collaborateurs
- [**AOUDIA Sofia**](https://github.com/aoudiasofia)
- [**PHILIPPOT Lucie**](https://github.com/luciephilippot)
- [**LECHEVALLIER Morgan**](https://github.com/morganlechevallier)


## 📄 Rapport de projet

  Vous pouvez consulter le rapport de projet en cliquant sur le lien,ci-dessous :

 - [📕 Rapport de projet (PDF)](rapport_projet.pdf)

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

---

## 📂 Structure du projet

### Fichiers principaux :
- **`Equipe.c`** : S'occupe de l'initialisation et de la gestion des équipes.
- **`CombattantJouer.c`** : Détermine le combattant prêt à jouer selon la jauge d’action.
- **`appliquerDegats.c`** : Gère l’application des dégâts à un combattant.
- **`affichage.c` / `affichage.h`** : Affiche des informations comme les équipes, les états et les actions.
- **`ActionOrdinateur.c`** : Définit le comportement de l'ordinateur.
- **`combat.c`** : Gère le déroulement d’un combat entre deux équipes.
- **`equipeKo.c`** : Vérifie si une équipe est K.O.
- **`essayerTechSpe.c`** : Vérifie si les techniques spéciales peuvent être utilisées.
- **`Makefile`** : Permet de compiler tous les fichiers en une seule commande.

### Fichiers de données :
- **`combattants.txt`** : Contient les caractéristiques des combattants.
- **`TechniquesSpeciales.txt`** : Liste des techniques spéciales disponibles.

### Autres fichiers :
- **`genererObjet.c`** : Génère aléatoirement un objet bonus.
- **`lectureCombattants.c`** : Lit les combattants depuis un fichier texte.
- **`lectureTechniques.c`** : Lit les techniques spéciales depuis un fichier texte.
- **`variables.c`** : Déclare les variables globales.
- **`couleurs.h`** : Définit les couleurs pour l’affichage.

---

## 🛠️ Installation et exécution

### Prérequis
- Un compilateur C (comme `gcc`).
- Un terminal compatible avec les séquences ANSI pour les couleurs.

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
    ```bash
   gcc -Wall -o CYFighter Equipe.c lectureCombattants.c variables.c lectureTechniques.c genererObjet.c afficheObjet.c ActionOrdinateur.c combat.c appliquerDegats.c appliquerEffetObjet.c CombattantJouer.c GererTourHumain.c essayerTechSpe.c equipeKo.c affichage.c 

3. Lancez le jeu :
    ```bash
    ./CYFighter

## 🎮 Comment jouer ?

1. Choisissez un mode de jeu :

    - Mode 1 : 2 joueurs.

    - Mode 2 : 1 joueur contre l'ordinateur.

2. Sélectionnez vos combattants :

    - Chaque joueur choisit 2 combattants parmi une liste.

3. Combattez ! :

    - Utilisez des attaques normales ou des techniques spéciales.

    - Exploitez les objets bonus pour prendre l'avantage.

3. Gagnez :
   -  Mettez l'équipe adverse K.O. pour remporter la victoire.


## 📜 Règles du jeu

-  Chaque joueur choisit 2 combattants.

- Chaque équipe dispose d'un objet bonus mystère.

- Les jauges de vitesse déterminent l'ordre des tours.

- Le but : mettre l'équipe adverse K.O.



## 📂 Répertoire des fichiers



  - appliquerDegats.c : S'occupe de l’application des dégâts à un combattant.

  - appliquerEffetObjet.c : Applique les effets des objets bonus.

  - ActionOrdinateur.c : Explique à l'ordinateur comment se comporter.

  - affichage.c / affichage.h : Fonctions qui affichent des informations comme les équipes, les états et les actions.

  - afficheObjet.c : Permet d'afficher les objets obtenus et les animations de chargement.

  - combat.c : Permet d'afficher le déroulement d’un combat entre deux équipes.

  - CombattantJouer.c : Détermine le combattant prêt à jouer selon la jauge d’action.

  - Equipe.c : S'occupe et initialise les équipes.

  - equipeKo.c : Vérifie si une équipe est K.O.

  - essayerTechSpe.c : Vérifie si on peut utiliser les techniques spéciales.

  - fichier.h : Définitions des structures, prototypes de fonctions et variables globales.

  - couleurs.h : Définitions des couleurs pour l’affichage.

  - combattants.txt : Caractéristiques des combattants.

  - TechniquesSpeciales.txt : Liste des techniques spéciales.

  - genererObjet.c : Génère aléatoirement un objet.

  - GererTourHumain.c : Guide l'utilisateur pendant sa partie.

  - lectureCombattants.c : Lecture des combattants depuis un fichier texte.

  - lectureTechniques.c : Lecture des techniques spéciales depuis un fichier texte.

  - Makefile : Permet de compiler tous les fichiers en même temps.

  - variables.c : Déclaration réelle des variables globales.
