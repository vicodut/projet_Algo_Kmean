/* inclusion des librairies */
#include "../headers/header.h"


void borderBW (color **tab, const int width, const int heigth)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, heigth);

	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j].b = 255;
			tab[i][j].g = 255;
			tab[i][j].r = 255;
		}
	}
}
