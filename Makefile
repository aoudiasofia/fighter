EXEC = CYFighter

# Sources à compiler
SRC = Equipe.c lectureCombattants.c variables.c lectureTechniques.c genererObjet.c afficheObjet.c ActionOrdinateur.c combat.c appliquerDegats.c appliquerEffetObjet.c CombattantJouer.c GererTourHumain.c essayerTechSpe.c equipeKo.c affichage.c

# Règle par défaut : compile et exécute
all: $(EXEC)
	./$(EXEC)

# Compilation du programme
$(EXEC): $(SRC) fichier.h affichage.h couleurs.h
	gcc -Wall -o $(EXEC) $(SRC)

# Nettoyage des fichiers compilés
clean: 
	rm -f $(EXEC)