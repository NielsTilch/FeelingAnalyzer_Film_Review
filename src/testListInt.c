#include <criterion/criterion.h>

#include "./../src/listSimpleChain_int.h"

ListeInt L0;
ListeInt L1;
ListeInt L2;
ListeInt L3;
ListeInt L4;
ListeInt L5;
ListeInt L6;
ListeInt L7;
ListeInt L8;

void setup(void) {
	L0 = listInt_creer();
	L1 = listInt_creer();
	listInt_ajoutFin(L1, 1);
	L2 = listInt_creer();
	listInt_ajoutFin(L2, 2);
	listInt_ajoutFin(L2, 4);
	L3 = listInt_creer();
	listInt_ajoutFin(L3, 10);
	listInt_ajoutFin(L3, 7);
	listInt_ajoutFin(L3, 12);
	L4 = concat(L0, L0);
	L5 = concat(L0, L1);
	L6 = concat(L1, L0);
	L7 = concat(L1, L2);
	L8 = concat(L2, L1);
}

void teardown(void) {
	freeList(L0);
	freeList(L1);
	freeList(L2);
	freeList(L3);
	freeList(L4);
	freeList(L5);
	freeList(L6);
	freeList(L7);
	freeList(L8);
}

Test(test_listInt, test_creer, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listInt_creer'");
	cr_assert_eq(L0->val, 0);
	cr_assert_eq(L0->suiv, NULL); 
}

Test(test_listInt, test_estVide, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listInt_estVide'");
	cr_assert_eq(listInt_estVide(L0), 1);
	cr_assert_eq(listInt_estVide(L1), 0);
}

Test(test_listInt, test_size, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listInt_size'");
	cr_assert_eq(listInt_size(L0), 0);
	cr_assert_eq(listInt_size(L1), 1);
	cr_assert_eq(listInt_size(L2), 2);
	cr_assert_eq(listInt_size(L3), 3);
	cr_assert_eq(listInt_size(L4), 0);
	cr_assert_eq(listInt_size(L5), 1);
	cr_assert_eq(listInt_size(L6), 1);
	cr_assert_eq(listInt_size(L7), 3);
}

Test(test_listInt, test_ajoutFin, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listInt_ajoutFin'");
	cr_assert_eq(L1->val, 1);
	cr_assert_null(L1->suiv);
	cr_assert_eq(L2->val, 2);
	cr_assert_eq(L2->suiv->val, 4);
	cr_assert_null(L2->suiv->suiv); 
}

Test(test_listInt, test_concat, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'concat'");
	cr_assert_eq(L4->val, 0);
	cr_assert_null(L4->suiv);
	cr_assert_eq(L5->val, 1);
	cr_assert_null(L5->suiv);
	cr_assert_eq(L6->val, 1);
	cr_assert_null(L6->suiv);
	cr_assert_eq(L7->val, 1);
	ListeInt cell = L7->suiv;
	cr_assert_eq(cell->val, 2);
	cell = cell->suiv;
	cr_assert_eq(L2->suiv->val, 4);
	cr_assert_null(cell->suiv);
}