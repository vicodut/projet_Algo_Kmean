/* inclusion des librairies */
#include "../headers/header.h"


int main(int argc, char const *argv[])
{
	if(argc > 1)
	{

//#####################################
//### DECLARATION DES VARIABLES
//#####################################
		char filename[20];
		struct headerFile header;

		FILE *fichier = NULL;
		FILE *fichierOut = NULL;
		strcpy(filename, argv[1]);

		fichier = fopen(filename, "rb");
		fichierOut = fopen("lenaOut.bmp", "wb");
		
		if (fichier)
		{
			readHeader(&header, fichier);

			switch(menu())
			{
				case 2:
					printf("\nGestion 2D.\n");
					tab2d(fichier, fichierOut, header);
				break;

				case 1:
					printf("\nGestion 1D.\n");
					tab1d(fichier, fichierOut, header);
				break;

				default:
				printf("Fin.\n");
					return 0;
				break;
			}
		}
	}

	return 0;

}
