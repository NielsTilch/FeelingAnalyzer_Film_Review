#include <criterion/criterion.h>

#include <stdio.h>
#include <stdlib.h>

#include "./../src/statistics.h"
#include "./../src/fonctionHachage.h"
#include "./../src/HashProg_collision.h"
#include "./../src/tableHachage_collision.h"
#include "./../src/listSimpleChain_collision.h"
#include "./../src/listSimpleChain_float.h"
#include "./../src/listSimpleChain_int.h"
#include "./../src/listSimpleChain_str.h"
#include "./../src/arbresFloat.h"
#include "./../src/arbres.h"

int numFonction;
TableHachage tab;
FILE* fichier;

void setup(void) {
	numFonction = 2;
	tab = tableHachage_creer(50);
	fichier = fopen("./../data/dataStatisticsTest.txt","r");	
	if (fichier == NULL) {
		printf("Erreur à l'ouverture\n");
	}
	tab = filledTab(fichier, tab, numFonction);
	tableHachage_visualiser(tab);
	fclose (fichier);		
}

void teardown(void) {
	freeTable(tab);
}

Test(test_statistics, test_avl_sortedOccurrence, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'avl_sortedOccurrence'");
	node* a = avl_sortedOccurrence(tab);
	//print_ordered_bst(a);
	cr_assert_eq(a->value, 2);
	cr_assert_null(a->parent);
	cr_assert_eq(a->son_l->value, 1);
	cr_assert_null(a->son_l->son_l);
	cr_assert_null(a->son_l->son_r);
	cr_assert_eq(a->son_r->value, 3);
	cr_assert_null(a->son_r->son_r);
	cr_assert_null(a->son_r->son_l);
}

Test(test_statistics, test_list_sortedOccurrence, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'list_sortedOccurrence'");
	node* a = avl_sortedOccurrence(tab);
	ListeInt l = list_sortedOccurrence(a);
	cr_assert_eq(l->val, 1);
	cr_assert_eq(l->suiv->val, 2);
	cr_assert_eq(l->suiv->suiv->val, 3);
	cr_assert_null(l->suiv->suiv->suiv);
}

Test(test_statistics, test_getSameOcurrenceWords, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'getSameOcurrenceWords'");
	ListeStr l = getSameOcurrenceWords(tab, 1);
	printf("La taille de la liste est : %d\n", listStr_size(l));
	//listStr_visualiser(l);
	cr_assert_str_eq(l->val, "e");
	cr_assert_null(l->suiv);
	l = getSameOcurrenceWords(tab, 2);
	printf("La taille de la liste est : %d\n", listStr_size(l));
	//listStr_visualiser(l);
	cr_assert_str_eq(l->val, "c");
	cr_assert_null(l->suiv);	
	l = getSameOcurrenceWords(tab, 3);
	printf("La taille de la liste est : %d\n", listStr_size(l));
	//listStr_visualiser(l);
	cr_assert_str_eq(l->val, "a");
	cr_assert_str_eq(l->suiv->val, "b");
	cr_assert_null(l->suiv->suiv);	
}

Test(test_statistics, test_getTableNumberWords, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'getTableNumberWords'");
	cr_assert_eq(getTableNumberWords(tab), 4);
}

Test(test_statistics, test_orderedWords, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'orderedWords'");
	char** t = orderedWords(tab);
	cr_assert_str_eq(t[0], "e");
	cr_assert_str_eq(t[1], "c");
	cr_assert_str_eq(t[2], "a");
	cr_assert_str_eq(t[3], "b");
}

Test(test_statistics, test_size_orderedWords, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'size_orderedWords'");
	printf("%d\n", size_orderedWords(tab));
	cr_assert_eq(size_orderedWords(tab), 4);
}

Test(test_statistics, test_avl_sortedScore, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'avl_sortedScore'");
	nodeFloat* a = avl_sortedScore(tab);
	print_ordered_bst_float(a);
	cr_assert_null(a->parent);
	cr_assert_eq(a->value, 2.5);
	cr_assert_eq(a->son_l->value, 2);
	cr_assert_null(a->son_l->son_l);
	cr_assert_null(a->son_l->son_r);
	cr_assert_eq(a->son_r->value, 3);
	cr_assert_null(a->son_r->son_l);
	cr_assert_null(a->son_r->son_r);	
}

Test(test_statistics, test_list_sortedScore, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'list_sortedScore'");
	nodeFloat* a = avl_sortedScore(tab);
	ListeFloat l = list_sortedScore(a);
	cr_assert_eq(l->val, 2);
	cr_assert_eq(l->suiv->val, 2.5);
	cr_assert_eq(l->suiv->suiv->val, 3);
	cr_assert_null(l->suiv->suiv->suiv);
}

Test(test_statistics, test_getWords, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'getWords'");
	char** t = getWords(tab, 2, 3);
	cr_assert_str_eq(t[0], "a");
	cr_assert_str_eq(t[1], "b");
	cr_assert_str_eq(t[2], "c");
	t = getWords(tab, 3, 5);
	cr_assert_str_eq(t[0], "e");
}

Test(test_statistics, test_averageScore, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'averageScore'");
	cr_assert_float_eq(averageScore(tab), 2.2222, 0.0001);
}
