Sortie: objet/main.o 
	gcc -g $^ -o $@

objet/main.o: src/main.c 
	gcc -g -c src/main.c -o objet/main.o

