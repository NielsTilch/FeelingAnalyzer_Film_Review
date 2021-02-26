#include <stdio.h>
#include <stdlib.h>

#include "fonctionHachage.h"
#include "listSimpleChain.h"
#include "tableHachage.h"
#include "HashProg.h"

TableHachage creer_HashageSansCollision(){
	//Création de la table de Hashage sans collision

	TableHachage tab = tableHachage_creer(1000);
	FILE* fichier = fopen("./../data/movie_reviews.txt","r");
	tab = filledTab(fichier, tab); 
	fclose (fichier);
	return tab;
}