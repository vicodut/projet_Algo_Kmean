<<<<<<< HEAD
Sortie: objects/main.o 
	gcc -g $^ -o $@  -pedantic -std=c99

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@  -pedantic -std=c99
=======
Sortie: objects/main.o objects/coloredBMP.o 
	gcc -g $^ -o $@  -pedantic -std=c99

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@  -pedantic -std=c99


objects/coloredBMP.o: src/coloredBMP.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

>>>>>>> dev_test
