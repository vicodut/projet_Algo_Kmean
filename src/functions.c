/* inclusion des librairies */
#include "../headers/header.h"
#include "../headers/kmeans.h"

int menu()
{
	int result;

	printf("\t\t -= Menu =-\n");
	printf("\t 1: Gestion 1D.\n");
	printf("\t 2: Gestion 2D.\n");
	printf("\t *: Quitter.\n");
	printf("$> ");

	scanf("%d", &result);
	return result;
}

void readHeader(struct headerFile* header, FILE *fichier)
{
	//#####################################
	//### LECTURE DE L ENTETE DU FICHIER
	//#####################################
		fread(header, sizeof(*header), DIM, fichier);


	//#####################################
	//### AFFICHAGE DES ENTETES
	//#####################################
		printf("\t - Entete du fichier - \n");
		printf("Signe du fichier : %c", header->sign[0]); printf("%c \n", header->sign[1]);
		printf("Taille du fichier : %d\n", header->size);
		printf("Champ reserve : %d\n", header->reserved);
		printf("Offset de l'image: %d\n\n", header->offset);

		printf("\n\t - Entete de l'image - \n");
		printf("Taille de l'entete de l'image : %d\n",  header->img.size);
		printf("Largeur de l'image : %d\n",  header->img.width);
		printf("Hauteur de l'image : %d\n",  header->img.height);
		printf("Nombre de plans : %hi\n",  header->img.plans);
		printf("Profondeur de codage : %hi\n",  header->img.depth);
		printf("Methode de compression : %d\n",  header->img.compr);
		printf("Taile de l'image : %d\n",  header->img.sizeTotal);
		printf("Resolution horizontale : %d\n",  header->img.hRes);
		printf("Resolution verticale : %d\n",  header->img.vRes);
		printf("Nombre de couleur : %d\n",  header->img.nbColor);
		printf("Nombre de couleur importante : %d\n",  header->img.nbColorImp);

		printf("Size of header: %d\n\n", sizeof(*header));
		printf("Size of HI: %d\n", sizeof(header->img));
		printf("Size of RGB: %d\n", sizeof(color));
}

void tab2d(FILE *fichier, FILE *fichierOut, struct headerFile header)
{
	int res = 0;
	int cluster = 0, iteration = 0;

	if (header.img.nbColor != 0)
	{
		printf("\n Codage des couleurs avec une palette\n");
		palette **tabColor = NULL;
		unsigned char **tabPix = NULL;


	//#####################################
	//### STOCKAGE DES COULEURS &modifs
	//#####################################
		tabColor = readPalette(tabColor, fichier, header.img.nbColor);
		tabPix = readBW(tabPix, header.img.width, header.img.height, fichier);
		borderBW(tabPix, header.img.width, header.img.height);


	//#####################################
	//### ECRITURE DE L ENTETE DU FICHIER
	//#####################################
		fwrite(&header, sizeof(header), DIM, fichierOut);
		writePalette(tabColor, fichierOut);


	//#####################################
	//### ECRITURE DES PIXELS
	//#####################################
		writeBW(tabPix, header.img.width, header.img.height, fichierOut);

	} else {
		printf("\n Codage des couleurs sans palette\n");
		color **tabColor = NULL;


	//#####################################
	//### STOCKAGE DES COULEURS & MODIFs
	//#####################################
		// ## ON REMPLI LE TABLEAU METHODE CLASSIQUE DOUBLE BOUCLE
		tabColor = readColor(tabColor, header.img.width, header.img.height, fichier);

		//----------------------------------------
		// - K-moyenne
		//----------------------------------------
		printf("- Kmoyenniser l'image ?\n");
		printf("1- Oui\n");
		printf("0- Non\n");
		printf("$> ");
		
		scanf("%d", &res);

		if (res == 1)
		{
			printf("========================\n");
			printf("- Nombre de noyeau: ");
			scanf("%d", &K);
			printf("- Nomre d'iteration: ");
			scanf("%d", &N);
			
			kmeans(tabColor, header.img.width, header.img.height, header);
		}

		//----------------------------------------
		// - Bordure
		//----------------------------------------
		printf("- Donner une bordure ?\n");
		printf("1- Oui\n");
		printf("0- Non\n");
		printf("$> ");
		
		scanf("%d", &res);

		if (res == 1)
		{
			borderColor(tabColor, header.img.width, header.img.height);
		}


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

}

void tab1d(FILE *fichier, FILE *fichierOut, struct headerFile header)
{
	if (header.img.nbColor != 0)
	{
		printf("\n Codage des couleurs avec une palette\n");
		palette *tabColor = NULL;
		unsigned char *tabPix = NULL;


	//#####################################
	//### STOCKAGE DES COULEURS
	//#####################################
		tabColor = readPalette1D(tabColor, fichier, header.img.nbColor);
		tabPix = readBW1D(tabPix, header.img.width, header.img.height, fichier);
		borderBW1D(tabPix, header.img.width, header.img.height);


	//#####################################
	//### ECRITURE DE L ENTETE DU FICHIER
	//#####################################
		fwrite(&header, sizeof(header), DIM, fichierOut);


	//#####################################
	//### ECRITURE DES PIXELS
	//#####################################
		writePalette1D(tabColor, fichierOut);
		writeBW1D(tabPix, header.img.width, header.img.height, fichierOut);

	} else {
		printf("\n Codage des couleurs sans palette\n");
		color *tabColor = NULL;


	//#####################################
	//### STOCKAGE DES COULEURS & MODIFs
	//#####################################
		// ## ON REMPLI LE TABLEAU METHODE CLASSIQUE DOUBLE BOUCLE
		tabColor = readColor1D(tabColor, header.img.width, header.img.height, fichier);
		borderColor1D(tabColor, header.img.width, header.img.height);


	//#####################################
	//### ECRITURE DE L ENTETE DU FICHIER
	//#####################################
		fwrite(&header, sizeof(header), DIM, fichierOut);


	//#####################################
	//### ECRITURE DES PIXELS
	//#####################################
		writeColor1D(tabColor, header.img.width, header.img.height, fichierOut);
	}



	// ## ON FERME LES FICHIERS
	fclose(fichier);
	fclose(fichierOut);

}