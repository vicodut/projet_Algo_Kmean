Sortie: objects/main.o objects/coloredBMP.o objects/bnwBMP.o objects/functions.o
	gcc -g $^ -o $@  -pedantic -std=c99

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/coloredBMP.o: src/coloredBMP.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/bnwBMP.o: src/bnwBMP.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/functions.o: src/functions.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

