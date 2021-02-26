#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "HashProg.h" 
#include "tableHachage.h"
#include "listSimpleChain.h"

void getWords(TableHachage tab) {
	int N = tab->tailleTableau;
	Liste list = tab->tableauListe;
	ELEMENT elmt = list->val;
	for (int i = 0; i < N; i++) {
		if (elmt.nbnote != 0) {
			printf("Le mot est %s.\n", elmt.clef);
		}
		list = list->suiv;
		elmt = list->val;
	}
}

int main() {

	TableHachage tab = tableHachage_creer(1000);
	FILE* fichier = fopen("./../data/movie_reviews.txt","r");
	tab = filledTab(fichier, tab); 
	tableHachage_visualiser(tab);
	//getWords(tab);
	fclose (fichier);

	// char string[] = "Hello World !";
	// char** mots = split(string);

	// int i = 0;
	// while (mots[i] != NULL) {
	// 	printf("Le mot est %s.\n", mots[i]);
	// 	i++;
	// }

	return 0;
}
