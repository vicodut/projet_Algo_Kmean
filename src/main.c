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

	switch(menu())
	{
		case 2:
			printf("\nImage Couleur. %d\n");
			strcpy(filename, "lenaColor.bmp");
		break;

		case 1:
			printf("\nImage Noir & blanc. %d\n");
			strcpy(filename, "lena.bmp");
		break;

		default:
		printf("Fin.\n");
			return 0;
		break;
	}

	fichier = fopen(filename, "rb");
	fichierOut = fopen("lenaOut.bmp", "wb");

	readHeader(&header, fichier);

	if (header.img.nbColor != 0)
	{
		printf("\n Codage des couleurs avec une palette\n");
		palette **tabColor = NULL;
		unsigned char **tabPix = NULL;


//#####################################
//### STOCKAGE DES COULEURS
//#####################################
		tabColor = readPalette(tabColor, fichier, header.img.nbColor);
		tabPix = readBW(tabPix, header.img.width, header.img.height, fichier);
		borderBW(tabPix, header.img.width, header.img.height);


//#####################################
//### ECRITURE DE L ENTETE DU FICHIER
//#####################################
		fwrite(&header, sizeof(header), DIM, fichierOut);


//#####################################
//### ECRITURE DES PIXELS
//#####################################
		writePalette(tabColor, fichierOut);
		writeBW(tabPix, header.img.width, header.img.height, fichierOut);

	} else {
		printf("\n Codage des couleurs sans palette\n");
		color **tabColor = NULL;


//#####################################
//### STOCKAGE DES COULEURS & MODIFs
//#####################################
		// ## ON REMPLI LE TABLEAU METHODE CLASSIQUE DOUBLE BOUCLE
		tabColor = readColor(tabColor, header.img.width, header.img.height, fichier);
		borderColor(tabColor, header.img.width, header.img.height);


//#####################################
//### ECRITURE DE L ENTETE DU FICHIER
//#####################################
		fwrite(&header, sizeof(header), DIM, fichierOut);


//#####################################
//### ECRITURE DES PIXELS
//#####################################
		writeColor(tabColor, header.img.width, header.img.height, fichierOut);
	}



	// ## ON FERME LES FICHIERS
	fclose(fichier);
	fclose(fichierOut);

	return 0;

}
