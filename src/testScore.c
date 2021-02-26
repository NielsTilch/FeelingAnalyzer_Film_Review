#include <stdlib.h>
#include <stdio.h>

#include "./../src/score_commentaire.h"
#include "./../src/HashProg_collision.h"
#include "./../src/tableHachage_collision.h"
#include "./../src/listSimpleChain_collision.h"

#include <criterion/criterion.h>

void setup(void) {
}

void teardown(void) { 
}

Test(test_score, test_calculScoreCommentaire) {

	puts("Test de la fonction 'score'");

	TableHachage tab = tableHachage_creer(10);
	ajouteNouveauMots("refreshing", tab, 4);
	ajouteNouveauMots("fantastic", tab, 3);
	ajouteNouveauMots("loved", tab, 3);
	ajouteNouveauMots("ok", tab, 3);
	ajouteNouveauMots("this", tab, 1);
	ajouteNouveauMots("movie", tab, 2);
	ajouteNouveauMots("terrible", tab, 1);
	ajouteNouveauMots("horrible", tab, 0);
	ajouteNouveauMots("sucks", tab, 0);

	char* com1 = "fantastic, refreshing movie";
	char* com2 = "horrible, terrible movie";
	char* com3 = "ok loved ";
	char* com4 = "this movie sucks";

	cr_expect_eq(score(com1, tab), 3.0);
	cr_expect_eq(score(com2, tab), 1.0);
	cr_expect_eq(score(com3, tab), 3.0);
	cr_expect_eq(score(com4, tab), 1.0);
}