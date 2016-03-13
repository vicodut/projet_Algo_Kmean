/* inclusion des librairies */
#include "../headers/header.h"

int menu()
{
	int result;

	printf("\t\t -= Menu =-\n");
	printf("\t 1: Image Noir et Blanc.\n");
	printf("\t 2: Image Couleur.\n");
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