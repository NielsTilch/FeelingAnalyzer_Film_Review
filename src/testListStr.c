#include <criterion/criterion.h>

#include "./../src/listSimpleChain_str.h"

ListeStr L0;
ListeStr L1;
ListeStr L2;
ListeStr L3;

void setup(void) {
	L0 = listStr_creer();
	L1 = listStr_creer();
	listStr_ajoutFin(L1, "a");
	L2 = listStr_creer();
	listStr_ajoutFin(L2, "a");
	listStr_ajoutFin(L2, "b");
	L3 = listStr_creer();
	listStr_ajoutFin(L3, "a");
	listStr_ajoutFin(L3, "b");
	listStr_ajoutFin(L3, "c");
}

void teardown(void) {
	freeListStr(L0);
	freeListStr(L1);
	freeListStr(L2);
	freeListStr(L3);
}

Test(test_listStr, test_creer, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listStr_creer'");
	cr_assert_eq(L0->val, NULL);
	cr_assert_eq(L0->suiv, NULL); 
}

Test(test_listStr, test_estVide, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listStr_estVide'");
	cr_assert_eq(listStr_estVide(L0), 1);
	cr_assert_eq(listStr_estVide(L1), 0);
}

Test(test_listStr, test_size, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listStr_size'");
	cr_assert_eq(listStr_size(L0), 0);
	cr_assert_eq(listStr_size(L1), 1);
	cr_assert_eq(listStr_size(L2), 2);
	cr_assert_eq(listStr_size(L3), 3);
}

Test(test_listStr, test_ajoutFin, .init = setup, .fini = teardown) {
	puts("Test de la fonction 'listStr_ajoutFin'");
	cr_assert_eq(L1->val, "a");
	cr_assert_null(L1->suiv);
	cr_assert_eq(L2->val, "a");
	cr_assert_eq(L2->suiv->val, "b");
	cr_assert_null(L2->suiv->suiv); 
}
