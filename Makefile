
PROG = projet

#sources 
SRC = main.c fonction.c affichege.c //(tout les fichiers qu'on doit compiler );;
#regle par defaut : compile et execute
all: $(PROG)
  ./$(PROG)

#compilation du  programme 
$(PROG): $(SRC) fichier.h
    gcc -Wall -o $(PROG) $(SRC)


#nettoyage

clean: 
  rm-f $(PROG)
