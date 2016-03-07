/* inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>

#define DIM 1

struct headerFile
{
	char sign[1];
	int size;
	int reserved;
	int offset;
};

struct headerImg
{
	int size;
	int width;
	int height;
	short plans;
	short depth;
	int compr;
	int sizeTotal;
	int hRes;
	int vRes;
	int nbColor;
	int nbColorImp;
};

struct color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char reserved;

};

void main(int argc, char const *argv[])
{
	int i = 0, j = 0;
	struct headerFile HF;
	struct headerImg HI;
	struct color **tabColor = NULL;

	FILE *fichier;
	FILE *fichierOut;
	fichier = fopen("lena.bmp", "rb");
	fichierOut = fopen("lenaOut.bmp", "wb");


//#####################################
//### LECTURE DE L ENTETE DU FICHIER
//#####################################
    fread(&HF.sign[0], sizeof(HF.sign[0]) , 1 , fichier);
    fread(&HF.sign[1], sizeof(HF.sign[1]) , 1 , fichier);
	fread(&HF.size, sizeof(HF.size), DIM, fichier);
	fread(&HF.reserved, sizeof(HF.reserved), DIM, fichier);
	fread(&HF.offset, sizeof(HF.offset), DIM, fichier);
	

//#####################################
//### LECTURE DE L ENTETE DE L IMAGE
//#####################################
	fread(&HI.size, sizeof(HI.size), DIM, fichier);
	fread(&HI.width, sizeof(HI.width), DIM, fichier);
	fread(&HI.height, sizeof(HI.height), DIM, fichier);
	fread(&HI.plans, sizeof(HI.plans), DIM, fichier);
	fread(&HI.depth, sizeof(HI.depth), DIM, fichier);
	fread(&HI.compr, sizeof(HI.compr), DIM, fichier);
	fread(&HI.sizeTotal, sizeof(HI.sizeTotal), DIM, fichier);
	fread(&HI.hRes, sizeof(HI.hRes), DIM, fichier);
	fread(&HI.vRes, sizeof(HI.vRes), DIM, fichier);
	fread(&HI.nbColor, sizeof(HI.nbColor), DIM, fichier);
	fread(&HI.nbColorImp, sizeof(HI.nbColorImp), DIM, fichier);

	printf("\t - Entete du fichier - \n");
	printf("Signe du fichier : %c", HF.sign[0]); printf("%c \n", HF.sign[1]);
	printf("Taille du fichier : %d\n", HF.size);
	printf("Champ reserve : %d\n", HF.reserved);
	printf("Offset de l'image: %d\n", HF.offset);


	printf("\n\t - Entete de l'image - \n");
	printf("Taille de l'entete de l'image : %d\n", HI.size);
	printf("Largeur de l'image : %d\n", HI.width);
	printf("Hauteur de l'image : %d\n", HI.height);
	printf("Nombre de plans : %headerImg\n", HI.plans);
	printf("Profondeur de codage : %hi\n", HI.depth);
	printf("Methode de compression : %d\n", HI.compr);
	printf("Taile de l'image : %d\n", HI.sizeTotal);
	printf("Resolution horizontale : %d\n", HI.hRes);
	printf("Resolution verticale : %d\n", HI.vRes);
	printf("Nombre de couleur : %d\n", HI.nbColor);
	printf("Nombre de couleur importante : %d\n", HI.nbColorImp);

	tabColor = (struct color**) malloc(HI.height*(sizeof(struct color*)));
	for (i = 0; i < HI.width; ++i)
	{
		tabColor[i] = (struct color*) malloc(HI.width*(sizeof(struct color)));
	}

	for (i = 0; i < HI.width; ++i)
	{
		for (j = 0; j < HI.height; ++j)
		{
			fread(&tabColor[i][j].r, sizeof(tabColor[i][j].r), DIM, fichier);
			fread(&tabColor[i][j].g, sizeof(tabColor[i][j].g), DIM, fichier);
			fread(&tabColor[i][j].b, sizeof(tabColor[i][j].b), DIM, fichier);
			fread(&tabColor[i][j].reserved, sizeof(tabColor[i][j].reserved), DIM, fichier);
		}
	}


//#####################################
//### ECRITURE DE L ENTETE DU FICHIER
//#####################################
	fwrite(&HF.sign[0], sizeof(HF.sign[0]), DIM, fichierOut);
	fwrite(&HF.sign[1], sizeof(HF.sign[1]), DIM, fichierOut);
	fwrite(&HF.size, sizeof(HF.size), DIM, fichierOut);
	fwrite(&HF.reserved, sizeof(HF.reserved), DIM, fichierOut);
	fwrite(&HF.offset, sizeof(HF.offset), DIM, fichierOut);


//#####################################
//### LECTURE DE L ENTETE DE L IMAGE
//#####################################
	fwrite(&HI.size, sizeof(HI.size), DIM, fichierOut);
	fwrite(&HI.width, sizeof(HI.width), DIM, fichierOut);
	fwrite(&HI.height, sizeof(HI.height), DIM, fichierOut);
	fwrite(&HI.plans, sizeof(HI.plans), DIM, fichierOut);
	fwrite(&HI.depth, sizeof(HI.depth), DIM, fichierOut);
	fwrite(&HI.compr, sizeof(HI.compr), DIM, fichierOut);
	fwrite(&HI.sizeTotal, sizeof(HI.sizeTotal), DIM, fichierOut);
	fwrite(&HI.hRes, sizeof(HI.hRes), DIM, fichierOut);
	fwrite(&HI.vRes, sizeof(HI.vRes), DIM, fichierOut);
	fwrite(&HI.nbColor, sizeof(HI.nbColor), DIM, fichierOut);
	fwrite(&HI.nbColorImp, sizeof(HI.nbColorImp), DIM, fichierOut);

	for (i = 0; i < HI.width; ++i)
	{
		for (j = 0; j < HI.height; ++j)
		{
			fwrite(&tabColor[i][j].r, sizeof(tabColor[i][j].r), DIM, fichierOut);
			fwrite(&tabColor[i][j].g, sizeof(tabColor[i][j].g), DIM, fichierOut);
			fwrite(&tabColor[i][j].b, sizeof(tabColor[i][j].b), DIM, fichierOut);
			fwrite(&tabColor[i][j].reserved, sizeof(tabColor[i][j].reserved), DIM, fichierOut);
		}
	}

	fclose(fichier);
	fclose(fichierOut);

}