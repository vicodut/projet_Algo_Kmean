/* inclusion des librairies */
#include "../headers/header.h"


void borderBW1D (unsigned char *tab, const int width, const int height)
{
	int i = 0, j = 0;

	
	for (i = 0; i < width * 10; ++i)
	{
		tab[i] = 255;
	}
	for (i = 0; i < width*height; i = i+width)
	{
		tab[i] = 255;
		for (j = 0; j < 10; ++j)
		{
			tab[i + j] = 255;
			tab[i - j] = 255;
		}
	}
	for (i = width * height; i > width * height - width * 10; i--)
	{
		tab[i + 1] = 255;
	}
}


unsigned char * readBW1D (unsigned char *tab, const int width, const int height, FILE *fichier)
{
	int i, j;

	tab = (unsigned char*) malloc( height * width * ( sizeof(unsigned char*) ));


	for (i = height * width ; i >= 0; --i)
	{

		fread(&tab[i], sizeof(tab[i]), DIM, fichier);

	}

	return tab;
}

void writeBW1D (unsigned char *tab, const int width, const int height, FILE *fichier)
{
	int i, j;
	
	for (i = height * width ; i >= 0; --i)
	{

		fwrite(&tab[i], sizeof( tab[i] ), DIM, fichier);

	}
}

palette * readPalette1D (palette *tab, FILE *fichier, int nbColor)
{
	int i = 0;
	
	tab = ( palette * ) malloc( nbColor*( sizeof(palette*) ));

	for (i = 0; i < 256; ++i)
	{
		fread(&tab[i], sizeof( tab[i] ), DIM, fichier);
	}

	return tab;
}

void writePalette1D (palette *tab, FILE *fichier)
{
	int i = 0;
	for (i = 0; i < 256; ++i)
	{
		fwrite(&tab[i], sizeof( tab[i] ), DIM, fichier);
	}
}

