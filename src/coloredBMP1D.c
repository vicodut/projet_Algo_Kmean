/* inclusion des librairies */
#include "../headers/header.h"


void borderColor1D (color *tab, const int width, const int height)
{
	int i = 0, j = 0;

	for (i = 0; i < 10; i = i + 1)
	{
		for (j = 0; j < width; ++j)
		{
			tab[i * height + j].b = 255;
			tab[i * height + j].g = 255;
			tab[i * height + j].r = 255;
			if (j >= 10 && j <= width - 11)
			{
				tab[i * height + j].b = 0;
				tab[i * height + j].g = 255;
				tab[i * height + j].r = 0;
			}
		}
	}

	for (i = (width * height) - 10 * height; i < width * height; i += height)
	{
		for (j = 0; j < width; ++j)
		{
			tab[i + j].b = 255;
			tab[i + j].g = 255;
			tab[i + j].r = 255;
			if (j >= 10 && j <= width - 11)
			{
				tab[i + j].b = 0;
				tab[i + j].r = 255;
				tab[i + j].g = 0;
			}
		}
	}

	for (i = width * 10; i < width * height - 10 * width; i = i + width)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i + j].g = 0;
			tab[i + j].r = 0;
			tab[i + j].b = 255;
		}
	}

	for (i = width * 10; i < width * height - 10 * width; i = i + width)
	{
		for (j = 1; j < 11; ++j)
		{
			tab[i - j + width].g = 0;
			tab[i - j + width].r = 0;
			tab[i - j + width].b = 0;
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