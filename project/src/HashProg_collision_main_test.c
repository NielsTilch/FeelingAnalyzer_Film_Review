#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "HashProg_collision.h" 
#include "tableHachage_collision.h"
#include "listSimpleChain_collision.h"
#include "fonctionHachage.h"

int main(){
	TableHachage tab = tableHachage_creer(15085);
	//FILE* fichier = fopen("./../src/datatest.txt","r");
	FILE* fichier = fopen("./../data/movie_reviews.txt","r");
	if (fichier == NULL){
		printf("Ereur à l'ouverture du fichier\n");
	}
	int numFonction = 1;
	//printf("Dans le main, num fonction vaut : %d\n",numFonction);
	printf("Dans le main, num fonction vaut : %d\n",numFonction);
	tab = filledTab(fichier, tab, numFonction); 
	tableHachage_visualiser(tab);
	fclose (fichier);
	freeTable(tab);
	return 0;
}
