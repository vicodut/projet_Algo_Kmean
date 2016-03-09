/* inclusion des librairies */
#include "../headers/header.h"


int main(int argc, char const *argv[])
{

//#####################################
//### DECLARATION DES VARIABLES
//#####################################
	int i = 0, j = 0;
	struct headerFile HF;
	struct headerImg HI;
	color **tabColor = NULL;

	FILE *fichier;
	FILE *fichierOut;
	//fichier = fopen("lena.bmp", "rb");
	fichier = fopen("lenaColor.bmp", "rb");
	fichierOut = fopen("lenaOut.bmp", "wb");


//#####################################
//### LECTURE DE L ENTETE DU FICHIER
//#####################################
	fread(&HF, sizeof(HF), DIM, fichier);


//#####################################
//### LECTURE DE L ENTETE DE L IMAGE
//#####################################
	fread(&HI, sizeof(HI), DIM, fichier);


//#####################################
//### AFFICHAGE DES ENTETES
//#####################################
	printf("\t - Entete du fichier - \n");
	printf("Signe du fichier : %c", HF.sign[0]); printf("%c \n", HF.sign[1]);
	printf("Taille du fichier : %d\n", HF.size);
	printf("Champ reserve : %d\n", HF.reserved);
	printf("Offset de l'image: %d\n", HF.offset);

	printf("\n\t - Entete de l'image - \n");
	printf("Taille de l'entete de l'image : %d\n", HI.size);
	printf("Largeur de l'image : %d\n", HI.width);
	printf("Hauteur de l'image : %d\n", HI.height);
	printf("Nombre de plans : %hi\n", HI.plans);
	printf("Profondeur de codage : %hi\n", HI.depth);
	printf("Methode de compression : %d\n", HI.compr);
	printf("Taile de l'image : %d\n", HI.sizeTotal);
	printf("Resolution horizontale : %d\n", HI.hRes);
	printf("Resolution verticale : %d\n", HI.vRes);
	printf("Nombre de couleur : %d\n", HI.nbColor);
	printf("Nombre de couleur importante : %d\n", HI.nbColorImp);

	printf("Size of HF: %d\n", sizeof(HF));
	printf("Size of HI: %d\n", sizeof(HI));
	printf("Size of RGB: %d\n", sizeof(color));


//#####################################
//### STOCKAGE DES COULEURS
//#####################################
	// ## DECLARATION DU TABLEAU DE STOCKAGE
	// ## PREMIERE PARTIE: LES LIGNES

	// ## <- color** -> : ON CAST (convertis) LES ADRESSES ALOUEES EN TABLEAU DE COLOR 0 2 DIMENTIONS
	// ## <- HI.height : la hauteur de l'image (nb de pixels en hauteur)
	// ## sizeof(color*) : la taille prise par un "pixel" (color* puisque c'est juste 1 ligne du tableau)
	tabColor = (color**) malloc(HI.height*(sizeof(color*)));

	// ## SECONDE PARTIE: LES COLONNES
	// ## MM PRICIPE QUE DESSUS SAUF QUE ON FAIT L'OPERATION POUR CHAQUES LIGNES
	for (i = 0; i < HI.width; ++i)
	{
		tabColor[i] = (color*) malloc(HI.width*(sizeof(color)));
	}

	// ## ON REMPLI LE TABLEAU METHODE CLASSIQUE DOUBLE BOUCLE
	for (i = 0; i < HI.height; ++i)
	{
		for (j = 0; j < HI.width; ++j)
		{
			fread(&tabColor[i][j].b, sizeof(tabColor[i][j].b), DIM, fichier);
			fread(&tabColor[i][j].g, sizeof(tabColor[i][j].g), DIM, fichier);
			fread(&tabColor[i][j].r, sizeof(tabColor[i][j].r), DIM, fichier);
			fread(&tabColor[i][j].reserved, sizeof(tabColor[i][j].reserved), DIM, fichier);
		}
	}

	//changeColor(tabColor, HI.width, HI.height);


//#####################################
//### ECRITURE DE L ENTETE DU FICHIER
//#####################################
	fwrite(&HF, sizeof(HF), DIM, fichierOut);


//#####################################
//### ECRITURE DE L ENTETE DE L IMAGE
//#####################################
	fwrite(&HI, sizeof(HI), DIM, fichierOut);


//#####################################
//### ECRITURE DES PIXELS
//#####################################
	for (i = 0; i < HI.height; ++i)
	{
		for (j = 0; j < HI.width; ++j)
		{
			fwrite(&tabColor[i][j].b, sizeof(tabColor[i][j].b), DIM, fichierOut);
			fwrite(&tabColor[i][j].g, sizeof(tabColor[i][j].g), DIM, fichierOut);
			fwrite(&tabColor[i][j].r, sizeof(tabColor[i][j].r), DIM, fichierOut);
			fwrite(&tabColor[i][j].reserved, sizeof(tabColor[i][j].reserved), DIM, fichierOut);
		}
	}


	// ## ON FERME LES FICHIERS
	fclose(fichier);
	fclose(fichierOut);

	return 0;

}
