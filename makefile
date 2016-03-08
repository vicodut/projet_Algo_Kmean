Sortie: objects/main.o objects/foo.o
	gcc -g $^ -o $@

objects/main.o: src/main.c headers/header.h
	gcc -g -c $< -o $@


objects/foo.o: src/foo.c headers/header.h
	gcc -g -c $< -o $@

