#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "./../src/analyseTable.h"
#include "./../src/HashProg_collision.h"
#include "./../src/tableHachage_collision.h"

#include <criterion/criterion.h>

void setup(void){
}

void teardown(void){
}

Test(test_compression,analyseTable){
	puts("Test de la fonction 'facteurCompression'");
	TableHachage tab = tableHachage_creer(10);
	FILE* fichier = fopen("./../src/datatest.txt","r");
	if (fichier == NULL){
		printf("Erreur à l'ouverture du fichier\n");
	}
	tab = filledTab(fichier,tab,1);
	float fcomp = facteurCompression(tab);
	cr_assert_float_eq(0.3,fcomp, 0.0000001);	
}
