PROG = projet

# Sources à compiler
SRC = Equipe.c lectureCombattants.c variables.c lectureTechniques.c genererObjet.c afficheObjet.c ActionOrdinateur.c combat.c appliquerDegats.c appliquerEffetObjet.c CombattantJouer.c GererTourHumain.c essayerTechSpe.c equipeKO.c affichage.c

# Règle par défaut : compile et exécute
all: $(PROG)
	./$(PROG)

# Compilation du programme
$(PROG): $(SRC) fichier.h affichage.h couleurs.h
	gcc -Wall -o $(PROG) $(SRC)

# Nettoyage des fichiers compilés
clean: 
	rm -f $(PROG)