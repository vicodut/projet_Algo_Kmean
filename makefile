Sortie: objects/main.o objects/coloredBMP.o objects/bnwBMP.o objects/functions.o objects/bnwBMP1D.o objects/coloredBMP1D.o objects/kmeans.o -lm
	gcc -g $^ -o $@  -pedantic -std=c99

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/coloredBMP.o: src/coloredBMP.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/coloredBMP1D.o: src/coloredBMP1D.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/bnwBMP.o: src/bnwBMP.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/bnwBMP1D.o: src/bnwBMP1D.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99

objects/functions.o: src/functions.c headers/header.h 
	gcc -g -c $< -o $@  -pedantic -std=c99	

objects/kmeans.o: src/kmeans.c headers/kmeans.h headers/header.h
	gcc -g -c $< -o $@  -pedantic -std=c99
