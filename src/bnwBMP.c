/* inclusion des librairies */
#include "../headers/header.h"


void borderBW (unsigned char **tab, const int width, const int height)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, height);

	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j] = 255;
		}
	}
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < height; ++j)
		{
			tab[i][j] = 255;
		}
	}
	for (i = width - 1; i > width - 11; --i)
	{
		for (j = 0; j < height; ++j)
		{
			tab[i][j] = 255;
		}
	}
	for (i = 0; i < width; ++i)
	{
		for (j = height - 1; j > height - 11; --j)
		{
			tab[i][j] = 255;
		}
	}
}


void readBW (unsigned char **tab, const int width, const int height, FILE *fichier)
{
	int i, j;

	for (i = height - 1; i >= 0; --i)
	{
		for (j = 0; j < width; ++j)
		{
			fread(&tab[i][j], sizeof(tab[i][j]), DIM, fichier);
		}
	}
}

void writeBW (unsigned char **tab, const int width, const int height, FILE *fichier)
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

void readPalette (palette **tab, FILE *fichier)
{
	int i = 0;
	for (i = 0; i < 256; ++i)
	{
		fread(&tab[i], sizeof(tab[i]), DIM, fichier);
	}

}

void writePalette (palette **tab, FILE *fichier)
{
	int i = 0;
	for (i = 0; i < 256; ++i)
	{
		fwrite(&tab[i], sizeof(tab[i]), DIM, fichier);
	}
}

