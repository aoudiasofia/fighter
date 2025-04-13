PROG = projet

# Sources à compiler
SRC = Equipe.c lectureCombattants.c lectureTechniques.c variables.c 

# Règle par défaut : compile et exécute
all: $(PROG)
	./$(PROG)

# Compilation du programme
$(PROG): $(SRC) fichier.h
	gcc -Wall -o $(PROG) $(SRC)

# Nettoyage des fichiers compilés
clean: 
	rm -f $(PROG)