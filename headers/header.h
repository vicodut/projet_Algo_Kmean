/* inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>


#define DIM 1

#pragma pack(1)


//#####################################
//### STRUCTURE DE L ENTETE DE L IMAGE
//#####################################
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



//#####################################
//### STRUCTURE DE L ENTETE DU FICHIER
//#####################################
struct headerFile
{
	char sign[2];
	int size;
	int reserved;
	int offset;

	struct headerImg img;
};


//#####################################
//### STRUCTURE DES PIXELS
//#####################################
typedef struct
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
//	unsigned char reserved;

} color;



//#####################################
//### FONCTIONS LOCALES
//#####################################
void borderColor (color **tab, const int width, const int heigth);