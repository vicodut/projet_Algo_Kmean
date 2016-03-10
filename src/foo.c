/* inclusion des librairies */
#include "../headers/header.h"


void changeColor (color **tab, const int width, const int heigth)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, heigth);

	for (i = 0; i < heigth; ++i)
	{
		for (j = 0; j < 10; ++j)
		{
			tab[i][j].b = 0;
			tab[i][j].g = 0;
			tab[i][j].r = 0;
		}
	}

}