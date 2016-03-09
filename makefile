Sortie: objects/main.o objects/foo.o 
	gcc -g $^ -o $@  -pedantic -std=c99

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@  -pedantic -std=c99


objects/foo.o: src/foo.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

