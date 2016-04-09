#include "../headers/kmeans.h"

//#####################################
//### METHODE DES KMEANS
//#####################################
void kmeans(color **tab, int width, int height, struct headerFile header)
{
	//#####################################
	//### DECLARATION DES VARIABLES
	//#####################################
	int i = 0, j = 0, x = 0, y = 0;
	clusters cluster[ K ];


	//----------------------------------
	// - Definition des noyeaux
	//---------------------------------- 
	srand(time(NULL));
	for (i = 0; i < K; ++i)
	{
		// On selectionne un pixel au hazard
		cluster[i].x = rand()%width;
		cluster[i].y = rand()%height;

		// On "ajoute" au total le 1er pixel
		cluster[i].totalX = cluster[i].x;
		cluster[i].totalY = cluster[i].y;

		// On récupère les couleurs de ce pixel
		cluster[i].b = tab[cluster[i].x][cluster[i].y].b;
		cluster[i].g = tab[cluster[i].x][cluster[i].y].g;
		cluster[i].r = tab[cluster[i].x][cluster[i].y].r;

		// On "ajoute" au total des couleurs les couleurs du pixel
		cluster[i].totalB = cluster[i].b;
		cluster[i].totalG = cluster[i].g;
		cluster[i].totalR = cluster[i].r;

		// On établi le nombre de pixel
		cluster[i].nbPixels = 1;
	}


	//----------------------------------
	// - Itération x N (voir var globales)
	//----------------------------------
	for (i = 0; i < N; ++i)
	{
		iterate(cluster, tab, width, height);
	}


	//----------------------------------
	// - On desinne les clusters
	//----------------------------------
	drawCluster(cluster, tab, width, height);

	//----------------------------------
	// - Paramètres d'entrée
	//----------------------------------
	printf("- Paramètre d'entree: - \n");
	printf("Nombre de noyeaux: %d \n"
		"Nombre d'itération: %d\n\n", K, N);

	//----------------------------------
	// - On affiche les données sur les diff cluster
	//----------------------------------
	for (i = 0; i < K; ++i)
	{
		printf("- Cluster n°%d -\n", i + 1);
		printf("Couleur: rgb(%d, %d, %d)\n", cluster[i].r, cluster[i].g, cluster[i].b);
		printf("Nombre de pixels: %d\n\n", cluster[i].nbPixels);
	}
}


void iterate(clusters cluster[K], color **tab, int width, int height)
{
	//#####################################
	//### DECLARATION DES VARIABLES
	//#####################################
	int i = 0, j = 0, index = 0;


	//---------------------------------- 
	// - Affectation des pixels a un cluster
	//---------------------------------- 
	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < height; ++j)
		{
			// findNearestCluster ::> Rếcupère le cluster le plus proche
			index = findNearestCluster(cluster, tab, i, j);
			
			// On incrémente le nb de pixel du cluster
			cluster[index].nbPixels++;

			// On ajoute les coordonées du nouveau pixels aux coord totales
			cluster[index].totalX += i;
			cluster[index].totalY += j;

			// On ajoute les couleurs du nv pixel aux couleurs totales
			cluster[index].totalB += tab[i][j].b;
			cluster[index].totalG += tab[i][j].g;
			cluster[index].totalR += tab[i][j].r;
		}
	}


	//---------------------------------- 
	// - Re-evaluation des noyeaux
	//---------------------------------- 
	for (i = 0; i < K; ++i)
	{
		// On rècupere les nouvelles coordonées (inutiles si on gere par couleur)
		cluster[i].x = cluster[i].totalX / cluster[i].nbPixels;
		cluster[i].y = cluster[i].totalY / cluster[i].nbPixels;

		// On rèupère la nouvelle couleur ==> moyenne des couleures totales
		cluster[i].b = cluster[i].totalB / cluster[i].nbPixels;
		cluster[i].g = cluster[i].totalG / cluster[i].nbPixels;
		cluster[i].r = cluster[i].totalR / cluster[i].nbPixels;

		// On réinitialise le cluster
		cluster[i].nbPixels = 1;
		cluster[i].totalY = cluster[i].y;
		cluster[i].totalX = cluster[i].x;

		cluster[i].totalB = cluster[i].b;
		cluster[i].totalG = cluster[i].g;
		cluster[i].totalR = cluster[i].r;

		// On récupère les couleurs du nouveau noyeau (inutile si on gere par couleur)
		// cluster[i].b = tab[cluster[i].x][cluster[i].y].b;
		// cluster[i].g = tab[cluster[i].x][cluster[i].y].g;
		// cluster[i].r = tab[cluster[i].x][cluster[i].y].r;
	}

}


int findNearestCluster(clusters cluster[K], color **tab, int x, int y)
{
//#####################################
//### DECLARATION DES VARIABLES
//#####################################
	int i = 0, j = 0;

	for (i = 1; i < K; ++i)
	{
		// Si on gere par distance par rappor au noyeau (diagramme de Voronoi)
		// if (dist(cluster[i].x, cluster[i].y, x, y) < dist(cluster[j].x, cluster[j].y, x, y))
		// {
		// 	j = i;
		// }

		// Si on gere par couleur ==> rgbDiff ::> Différence entre 2 couleurs
		if (rgbDiff(cluster[i], tab[x][y]) < rgbDiff(cluster[j], tab[x][y]) )
		{
			j = i;
		}
	}
	return j;
}


int dist(int xa, int ya, int xb, int yb)
{
	//#####################################
	//### FORMULE DISTANCE ENTRE 2 POINTS:
	//### AB = racine((xB - xA)**2 + (yB - yA)**2)
	//#####################################
	int x = xb - xa;
	int y = yb - ya;

	return sqrt(pow(x,2) + pow(y,2));
}


int rgbDiff(clusters cluster, color tab)
{
	//#####################################
	//### RECUPERE LES DONNEES DE COULEUR
	//### RENVOIE LA DIFFERENCE
	//#####################################
	int r = cluster.r - tab.r;
	int g = cluster.g - tab.g;
	int b = cluster.b - tab.b;

	return sqrt(pow(r,2) + pow(g,2) + pow(b,2));
}


void drawCluster(clusters cluster[K], color **tab, int width, int height)
{
	//#####################################
	//### DECLARATION DES VARIABLES
	//#####################################
	int i = 0, j = 0, index = 0;


	//---------------------------------- 
	// - On dessine les cluster sur l'image
	//---------------------------------- 
	for (i = 0; i < width; ++i)
	{
		for (j = 0; j < height; ++j)
		{
			// On recuperer le cluster le plus proche
			index = findNearestCluster(cluster, tab, i, j);
			
			tab[i][j].r = cluster[index].r;
			tab[i][j].b = cluster[index].b;
			tab[i][j].g = cluster[index].g;

			cluster[index].nbPixels++;
		}
	}
}