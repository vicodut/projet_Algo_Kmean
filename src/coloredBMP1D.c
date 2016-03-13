/* inclusion des librairies */
#include "../headers/header.h"


void borderColor1D (color *tab, const int width, const int heigth)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, heigth);

	

}

color * readColor1D (color *tab, const int width, const int height, FILE *fichier)
{
	int i;

	tab = ( color * ) malloc( height * width * ( sizeof(color*) ));

	for (i = height * width - 1; i >= 0; --i)
	{

		fread(&tab[i], sizeof( tab[i] ), DIM, fichier);
		
	}
	return tab;
}

void writeColor1D (color *tab, const int width, const int height, FILE *fichier)
{
	int i;
	
	for (i = height * width - 1; i >= 0; --i)
	{

		fwrite(&tab[i], sizeof( tab[i] ), DIM, fichier);
	}
}