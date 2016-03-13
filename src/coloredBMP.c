/* inclusion des librairies */
#include "../headers/header.h"


void borderColor (color **tab, const int width, const int heigth)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, heigth);

	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j].b = 255;
			tab[i][j].g = 255;
			tab[i][j].r = 255;
		}
	}

	for (i = heigth - 1; i >= heigth - 11; --i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j].b = 255;
			tab[i][j].g = 255;
			tab[i][j].r = 255;
		}
	}

	for (i = heigth - 1; i >= heigth - 11; --i)
	{
		for (j = width - 1; j >= width - 11; --j)
		{
			tab[i][j].b = 255;
			tab[i][j].g = 255;
			tab[i][j].r = 255;
		}
	}

	for (i = 0; i < 10; ++i)
	{
		for (j = width - 1; j >= width - 11; --j)
		{
			tab[i][j].b = 255;
			tab[i][j].g = 255;
			tab[i][j].r = 255;
		}
	}
	for (i = 10; i < heigth - 11; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j].b = 0;
			tab[i][j].g = 0;
			tab[i][j].r = 0;
		}
	}

	for (i = heigth - 1; i >= heigth - 11; --i)
	{
		for (j = 10; j < width - 11; ++j)
		{
			tab[i][j].b = 0;
			tab[i][j].g = 0;
			tab[i][j].r = 255;
		}
	}

	for (i = heigth - 12; i >= 0 + 10; --i)
	{
		for (j = width - 1; j >= width - 11; --j)
		{
			tab[i][j].b = 255;
			tab[i][j].g = 0;
			tab[i][j].r = 0;
		}
	}

	for (i = 0; i < 10; ++i)
	{
		for (j = width - 12; j >= 0 + 10; --j)
		{
			tab[i][j].b = 0;
			tab[i][j].g = 255;
			tab[i][j].r = 0;
		}
	}

}

color ** readColor (color **tab, const int width, const int height, FILE *fichier)
{
	int i, j;

	

	tab = (color**) malloc( height*(sizeof(color*)));

	for (i = 0; i < height; ++i)
	{
		tab[i] = (color*) malloc( width*(sizeof(color)));
	}

	for (i = height - 1; i >= 0; --i)
	{
		for (j = 0; j < width; ++j)
		{
			fread(&tab[i][j], sizeof(tab[i][j]), DIM, fichier);
		}
	}
	return tab;
}

void writeColor (color **tab, const int width, const int height, FILE *fichier)
{
	int i, j;
	
	for (i = height - 1; i >= 0; --i)
	{
		for (j = 0; j < width; ++j)
		{
			fwrite(&tab[i][j], sizeof(tab[i][j]), DIM, fichier);
		}
	}
}