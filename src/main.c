/* inclusion des librairies */
#include "../headers/header.h"


int main(int argc, char const *argv[])
{

//#####################################
//### DECLARATION DES VARIABLES
//#####################################
	int i = 0, j = 0;
	char tamp = 0;
	struct headerFile header;
	color **tabColor = NULL;

	FILE *fichier;
	FILE *fichierOut;
	fichier = fopen("lena.bmp", "rb");
	//fichier = fopen("lenaColor.bmp", "rb");
	fichierOut = fopen("lenaOut.bmp", "wb");


//#####################################
//### LECTURE DE L ENTETE DU FICHIER
//#####################################
	fread(&header, sizeof(header), DIM, fichier);


//#####################################
//### AFFICHAGE DES ENTETES
//#####################################
	printf("\t - Entete du fichier - \n");
	printf("Signe du fichier : %c", header.sign[0]); printf("%c \n", header.sign[1]);
	printf("Taille du fichier : %d\n", header.size);
	printf("Champ reserve : %d\n", header.reserved);
	printf("Offset de l'image: %d\n\n", header.offset);

	printf("\n\t - Entete de l'image - \n");
	printf("Taille de l'entete de l'image : %d\n",  header.img.size);
	printf("Largeur de l'image : %d\n",  header.img.width);
	printf("Hauteur de l'image : %d\n",  header.img.height);
	printf("Nombre de plans : %hi\n",  header.img.plans);
	printf("Profondeur de codage : %hi\n",  header.img.depth);
	printf("Methode de compression : %d\n",  header.img.compr);
	printf("Taile de l'image : %d\n",  header.img.sizeTotal);
	printf("Resolution horizontale : %d\n",  header.img.hRes);
	printf("Resolution verticale : %d\n",  header.img.vRes);
	printf("Nombre de couleur : %d\n",  header.img.nbColor);
	printf("Nombre de couleur importante : %d\n",  header.img.nbColorImp);

	printf("Size of header: %d\n\n", sizeof(header));
	printf("Size of HI: %d\n", sizeof(header.img));
	printf("Size of RGB: %d\n", sizeof(color));


//#####################################
//### STOCKAGE DES COULEURS
//#####################################
	// ## DECLARATION DU TABLEAU DE STOCKAGE
	// ## PREMIERE PARTIE: LES LIGNES

	// ## <- color** -> : ON CAST (convertis) LES ADRESSES ALOUEES EN TABLEAU DE COLOR 0 2 DIMENTIONS
	// ## <- HI.height : la hauteur de l'image (nb de pixels en hauteur)
	// ## sizeof(color*) : la taille prise par un "pixel" (color* puisque c'est juste 1 ligne du tableau)
	tabColor = (color**) malloc( header.img.height*(sizeof(color*)));

	// ## SECONDE PARTIE: LES COLONNES
	// ## MM PRICIPE QUE DESSUS SAUF QUE ON FAIT L'OPERATION POUR CHAQUES LIGNES
	for (i = 0; i < header.img.width; ++i)
	{
		tabColor[i] = (color*) malloc( header.img.width*(sizeof(color)));
	}

	// ## ON REMPLI LE TABLEAU METHODE CLASSIQUE DOUBLE BOUCLE
	for (i = header.img.height - 1; i >= 0; --i)
	{
		for (j = 0; j < header.img.width; ++j)
		{
			fread(&tabColor[i][j], sizeof(tabColor[i][j]), DIM, fichier);
		}
	}

	borderBW(tabColor, header.img.width, header.img.height);


//#####################################
//### ECRITURE DE L ENTETE DU FICHIER
//#####################################
	fwrite(&header, sizeof(header), DIM, fichierOut);


//#####################################
//### ECRITURE DES PIXELS
//#####################################
	for (i = header.img.height - 1; i >= 0; --i)
	{
		for (j = 0; j <  header.img.width; ++j)
		{
			fwrite(&tabColor[i][j], sizeof(tabColor[i][j]), DIM, fichierOut);
		}
	}


	// ## ON FERME LES FICHIERS
	fclose(fichier);
	fclose(fichierOut);

	return 0;

}
