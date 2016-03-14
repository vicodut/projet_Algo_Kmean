/* inclusion des librairies */
#include "../headers/header.h"


void borderColor1D (color *tab, const int width, const int height)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, height);

	for (i = 0; i < 10; i = i + 1)
	{
		for (j = 0; j < width; ++j)
		{
			if (j >= 10 && i <= width - 10)
			{
				tab[i * height + j].b = 0;
				tab[i * height + j].g = 255;
				tab[i * height + j].r = 0;
			}
		}
	}

	for (i = 0; i < width * height; i = i + width)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i + j].b = 255;
			tab[i + j].g = 255;
			tab[i + j].r = 255;	
			tab[i - j].b = 255;
			tab[i - j].g = 255;
			tab[i - j].r = 255;	
			if (i >= 10 * width && i <= width * height - 10 * width)
			{
				tab[i + j].g = 0;
				tab[i + j].r = 0;
				tab[i - j].b = 0;
				tab[i - j].g = 0;
				tab[i - j].r = 0;	
			}
		}
	}

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