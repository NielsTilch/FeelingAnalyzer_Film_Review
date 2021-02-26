#include <criterion/criterion.h>

#include "./../src/listSimpleChain_float.h"

ListeFloat L0;
ListeFloat L1;
ListeFloat L2;
ListeFloat L3;
ListeFloat L4;
ListeFloat L5;
ListeFloat L6;
ListeFloat L7;
ListeFloat L8;

void setup(void) {
	L0 = listFloat_creer();
	L1 = listFloat_creer();
	listFloat_ajoutFin(L1, 0.6366);
	L2 = listFloat_creer();
	listFloat_ajoutFin(L2, 3.3478);
	listFloat_ajoutFin(L2, 1.9502);
	L3 = listFloat_creer();
	listFloat_ajoutFin(L3, 2.8461);
	listFloat_ajoutFin(L3, 1.9064);
	listFloat_ajoutFin(L3, 2.3921);
	L4 = listFloat_concat(L0, L0);
	L5 = listFloat_concat(L0, L1);
	L6 = listFloat_concat(L1, L0);
	L7 = listFloat_concat(L1, L2);
	L8 = listFloat_concat(L2, L1);
}

void teardown(void) {
	freeListFloat(L0);
	freeListFloat(L1);
	freeListFloat(L2);
	freeListFloat(L3);
	freeListFloat(L4);
	freeListFloat(L5);
	freeListFloat(L6);
	freeListFloat(L7);
	freeListFloat(L8);
}

Test(test_listFloat, test_creer, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listFloat_creer'");
	cr_assert_eq(L0->val, 0);
	cr_assert_eq(L0->suiv, NULL); 
}

Test(test_listFloat, test_estVide, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listFloat_estVide'");
	cr_assert_eq(listFloat_estVide(L0), 1);
	cr_assert_eq(listFloat_estVide(L1), 0);
}

Test(test_listFloat, test_size, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listFloat_size'");
	cr_assert_eq(listFloat_size(L0), 0);
	cr_assert_eq(listFloat_size(L1), 1);
	cr_assert_eq(listFloat_size(L2), 2);
	cr_assert_eq(listFloat_size(L3), 3);
	cr_assert_eq(listFloat_size(L4), 0);
	cr_assert_eq(listFloat_size(L5), 1);
	cr_assert_eq(listFloat_size(L6), 1);
	cr_assert_eq(listFloat_size(L7), 3);
}

Test(test_listFloat, test_ajoutFin, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listFloat_ajoutFin'");
	cr_assert_float_eq(L1->val, 0.6366, 0.0000001);
	cr_assert_null(L1->suiv);
	cr_assert_float_eq(L2->val, 3.3478, 0.0000001);
	cr_assert_float_eq(L2->suiv->val, 1.9502, 0.0000001);
	cr_assert_null(L2->suiv->suiv); 
}

Test(test_listFloat, test_concat, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listFloat_concat'");
	cr_assert_eq(L4->val, 0);
	cr_assert_null(L4->suiv);
	cr_assert_float_eq(L5->val, 0.6366, 0.0000001);
	cr_assert_null(L5->suiv);
	cr_assert_float_eq(L6->val, 0.6366, 0.0000001);
	cr_assert_null(L6->suiv);
	cr_assert_float_eq(L7->val, 0.6366, 0.0000001);
	ListeFloat cell = L7->suiv;
	cr_assert_float_eq(cell->val, 3.3478, 0.0000001);
	cell = cell->suiv;
	cr_assert_float_eq(L2->suiv->val, 1.9502, 0.0000001);
	cr_assert_null(cell->suiv);
}