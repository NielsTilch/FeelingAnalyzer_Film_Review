#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fonctionHachage.h"
#include "listSimpleChain_collision.h"
#include "HashProg_collision.h"
#include "tableHachage_collision.h"
#include "analyseTable.h"

int main(){
	char* cheminFichier="./../data/movie_reviews.txt";
	printf("C'est parti !\n");
	//moyTempsRemplissage(cheminFichier,2,6000,5800);
	int N = 15085;
	int numFonction = 1;
	FILE* fichier = fopen(cheminFichier,"r");
	if (fichier == NULL){
		printf("Erreur à l'ouverture des fichiers");
		return(0);
	}	
	TableHachage tab = tableHachage_creer(N);
	filledTab(fichier,tab,numFonction);
	//printf("Pour la fonction %d, le facteur de compression est : %f\n",5,facteurCompression(tab));
	printf("Pour la fonction %d, le temps recherche mot est : %f\n",numFonction,tpsRechercheMot(tab,cheminFichier,numFonction));
	freeTable(tab);
	return(1);
}
