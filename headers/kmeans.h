/* inclusion des librairies */
#include <math.h>
#include <time.h>
#include "header.h"


//#####################################
//### K ==> NOMBRE DE NOYEAUX
//### N ==> NOMBRE D'ITERATION
//#####################################
//#define K 7
//#define N 10

//#####################################
//### STRUCTURE CLUSTERS
//#####################################
typedef struct 
{
	unsigned int x;
	unsigned int y;

	unsigned int totalX;
	unsigned int totalY;
	unsigned int nbPixels;

	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned int totalR;
	unsigned int totalG;
	unsigned int totalB;

} clusters;


//#####################################
//### INITIALISATION DES FONCTIONS
//#####################################
void kmeans(color **tab, int width, int height, struct headerFile header);
void iterate(clusters cluster[K], color **tab, int width, int height);
int findNearestCluster(clusters cluster[K], color **tab, int x, int y);
int dist(int xa, int xb, int ya, int yb);
void drawCluster(clusters cluster[K], color **tab, int width, int height);
int rgbDiff(clusters cluster, color tab);