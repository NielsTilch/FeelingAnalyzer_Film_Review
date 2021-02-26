#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "statistics.h"
#include "fonctionHachage.h"
#include "HashProg_collision.h"
#include "tableHachage_collision.h"
#include "listSimpleChain_collision.h"
#include "listSimpleChain_float.h"
#include "listSimpleChain_int.h"
#include "listSimpleChain_str.h"
#include "arbresFloat.h"
#include "arbres.h"

int main() {

	TableHachage tab = tableHachage_creer(20000);
	FILE* fichier = fopen("./../data/movie_reviews.txt","r");
	int numFonction = 1;
	tab = filledTab(fichier, tab,numFonction);
	fclose (fichier);
	//tableHachage_visualiser(tab);
	node* arbre = avl_sortedOccurrence(tab);
	ListeInt liste = list_sortedOccurrence(arbre);
	//listInt_visualiser(liste);

	ListeStr mots = getSameOcurrenceWords(tab, 7282);
	//listStr_visualiser(mots);
	printf("La taille de mots est : %d\n", listStr_size(mots));

	//printf("Le nombre de mots dans la table est de %d.\n", getTableNumberWords(tab));
	//print_leastRecurrentWords(tab, 20); 
	//print_mostRecurrentWords(tab, 1180);
	
	return 0;
}