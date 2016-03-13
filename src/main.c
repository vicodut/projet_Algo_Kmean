/* inclusion des librairies */
#include "../headers/header.h"


int main(int argc, char const *argv[])
{

//#####################################
//### DECLARATION DES VARIABLES
//#####################################
	char filename[20];
	struct headerFile header;

	FILE *fichier;
	FILE *fichierOut;
	//strcpy(filename, "lenaColor.bmp");
	strcpy(filename, "lena.bmp");

	fichier = fopen(filename, "rb");
	fichierOut = fopen("lenaOut.bmp", "wb");

	readHeader(&header, fichier);

	switch(menu())
	{
		case 2:
			printf("\nGestion 2D. %d\n");
			tab2d(fichier, fichierOut, header);
		break;

		case 1:
			printf("\nGestion 1D. %d\n");
			tab1d(fichier, fichierOut, header);
		break;

		default:
		printf("Fin.\n");
			return 0;
		break;
	}

	return 0;

}
