/* inclusion des librairies */
#include "../headers/header.h"


void changeColor (color **tab, const int width, const int heigth)
{
	int i = 0, j = 0;
	printf("Hello World + %d + %d\n", width, heigth);

	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < heigth; ++j)
		{
			tab[i][j].b = '1';
		}
	}

}