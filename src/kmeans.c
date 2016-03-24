#include "../headers/header.h"

	// 1: Noyeaux
	// 2: Mise à jours des clusters
	// 3: Re evaluation des noyeaux
	// 4: Itération

void kmeans(unsigned char **tab, const int width, const int height)
{
//#####################################
//### DECLARATION DES VARIABLES
//#####################################
	int i = 0, j = 0, z = 0, index;
	clusters cluster[ K ];

	//----------------------------------
	// - Definition des noyeaux
	//---------------------------------- 
	for (i = 0; i < K; ++i)
	{
		cluster[i].x = rand();
		cluster[i].y = rand();
	}

	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < height; ++j)
		{
			index = findNearestCluster(cluster, tab, i, j);
		}
	}
}

int findNearestCluster(clusters cluster[K], unsigned char **tab, int x, int y)
{
//#####################################
//### DECLARATION DES VARIABLES
//#####################################
	int length = x + y, i = 0, j = 0;

	for (i = 1; i < K; ++i)
	{
		if (cluster[j].x + cluster[j].y > cluster[i].x + cluster[i].y)
		{
			j = i;
		}
	}

	return j;
}