Sortie: objects/main.o 
	gcc -g $^ -o $@

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@

