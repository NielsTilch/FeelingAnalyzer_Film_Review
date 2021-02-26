#include <criterion/criterion.h>

#include "./../src/arbresFloat.h"

nodeFloat* t0;
nodeFloat* t1;
nodeFloat* t2;
nodeFloat* t3;
nodeFloat* t4;
nodeFloat* t5;
nodeFloat* t6;
nodeFloat* t7;
nodeFloat* t8;
nodeFloat* t9;

void setup(void) {
	t0 = NULL;
	t1 = new_binary_tree_float(12.1);
	t2 = new_binary_tree_float(5.12);
	t3 = addFloat(t2, 10.1);
	t4 = new_binary_tree_float(20.1);
	t5 = addFloat(t4, 7.12);
	t6 = addFloat(t5, 51.1);
	t7 = addFloat(t6, 4.12);
	t8 = addFloat(t7, 17.1);
	t9 = rightRotateFloat(t8);	
}

void teardown(void) {
}

Test(test_arbresFloat, test_creer, .init = setup) {
	puts("Test de la fonction 'new_binary_tree'");
	cr_assert_float_eq(t1->value, 12.1, 0.000001);
	cr_assert_null(t1->son_l);
	cr_assert_null(t1->son_r);
	cr_assert_null(t1->parent);
}

Test(test_arbresFloat, test_isEmpty, .init = setup) {
	puts("Test de la fonction 'isEmpty'");
	cr_assert_eq(isEmptyFloat(t0), 1);
	cr_assert_eq(isEmptyFloat(t1), 0);
}

Test(test_arbresFloat, test_least, .init = setup) {
	puts("Test de la fonction 'least'");
	cr_assert_eq(leastFloat(t0), 0);
	cr_assert_float_eq(leastFloat(t1), 12.1, 0.000001);
	cr_assert_float_eq(leastFloat(t3), 5.12, 0.000001);
	cr_assert_float_eq(leastFloat(t8), 4.12, 0.000001);
}

Test(test_arbresFloat, test_greatest, .init = setup) {
	puts("Test de la fonction 'greatest'");
	cr_assert_eq(greatestFloat(t0), 0);
	cr_assert_float_eq(greatestFloat(t1), 12.1, 0.000001);
	cr_assert_float_eq(greatestFloat(t3), 10.1, 0.000001);
	cr_assert_float_eq(greatestFloat(t8), 51.1, 0.00001);	
}

Test(test_arbresFloat, test_makeRoot, .init = setup) {
	puts("Test de la fonction 'makeRoot'"); 
	nodeFloat* t = makeRootFloat(t0, 2.12, t0);
	cr_assert_float_eq(t->value, 2.12, 0.000001);
	cr_assert_null(t->son_l);
	cr_assert_null(t->son_r);
	cr_assert_null(t->parent);

	t = makeRootFloat(t1, 21.1, t0);
	nodeFloat* noeud = t->son_l;
	cr_assert_float_eq(t->value, 21.1, 0.000001);
	cr_assert_null(t->parent);
	cr_assert_null(t->son_r);
	cr_assert_float_eq(noeud->value, 12.1, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);

	t = makeRootFloat(t0, 10.1, t1);
	noeud = t->son_r;
	cr_assert_float_eq(t->value, 10.1, 0.000001);
	cr_assert_null(t->parent);
	cr_assert_null(t->son_l);
	cr_assert_float_eq(noeud->value, 12.1, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	

	t = makeRootFloat(t2, 7.12, t1);
	noeud = t->son_l;
	cr_assert_float_eq(t->value, 7.12, 0.000001);
	cr_assert_null(t->parent);
	cr_assert_float_eq(noeud->value, 5.12, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	
	noeud = t->son_r;
	cr_assert_float_eq(noeud->value, 12.1, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
}

Test(test_arbresFloat, test_hasLeft, .init = setup) {
	puts("Test de la fonction 'hasLeft'");
	cr_assert_eq(hasLeftFloat(t0), 0);
	cr_assert_eq(hasLeftFloat(t1), 0);
	cr_assert_eq(hasLeftFloat(t3), 0);
	cr_assert_eq(hasLeftFloat(t5), 1);
	cr_assert_eq(hasLeftFloat(t8), 1);
}

Test(test_arbresFloat, test_hasRight, .init = setup) {
	puts("Test de la fonction 'hasRight'");
	cr_assert_eq(hasRightFloat(t0), 0);
	cr_assert_eq(hasRightFloat(t1), 0);
	cr_assert_eq(hasRightFloat(t3), 1);
	cr_assert_eq(hasRightFloat(t5), 0);
	cr_assert_eq(hasRightFloat(t8), 1);
}

Test(test_arbresFloat, test_has, .init = setup) {
	puts("Test de la fonction 'has'");
	cr_assert_eq(hasFloat(t0, 2.12), 0);
	cr_assert_eq(hasFloat(t1, 12.1), 1);
	cr_assert_eq(hasFloat(t3, 5.12), 1);
	cr_assert_eq(hasFloat(t8, 1.12), 0);
}

Test(test_arbresFloat, test_add, .init = setup) {
	puts("Test de la fonction 'add'");
	nodeFloat* noeud = t5->son_l;
	cr_assert_float_eq(t5->value, 20.1, 0.000001);
	cr_assert_null(t5->parent);
	cr_assert_null(t5->son_r);
	cr_assert_float_eq(noeud->value, 7.12, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);

	noeud = t3->son_r;
	cr_assert_float_eq(t3->value, 5.12, 0.000001);
	cr_assert_null(t3->parent);
	cr_assert_null(t3->son_l);
	cr_assert_float_eq(noeud->value, 10.1, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	

	noeud = t6->son_l;
	cr_assert_float_eq(t6->value, 20.1, 0.000001);
	cr_assert_null(t6->parent);
	cr_assert_float_eq(noeud->value, 7.12, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t6->son_r;
	cr_assert_float_eq(noeud->value, 51.1, 0.00001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	
}

Test(test_arbresFloat, test_height, .init = setup) {
	puts("Test de la fonction 'height'");
	cr_assert_eq(heightFloat(t0), 0);
	cr_assert_eq(heightFloat(t1), 1);
	cr_assert_eq(heightFloat(t3), 2);
	cr_assert_eq(heightFloat(t6), 2);
	cr_assert_eq(heightFloat(t8), 3);
}

Test(test_arbresFloat, test_balance, .init = setup) {
	puts("Test de la fonction 'balance'");
	cr_assert_eq(balanceFloat(t0), 0);
	cr_assert_eq(balanceFloat(t1), 0);
	cr_assert_eq(balanceFloat(t3), -1);
	cr_assert_eq(balanceFloat(t5), 1);
	cr_assert_eq(balanceFloat(t6), 0);
	cr_assert_eq(balanceFloat(t8), 1);
}

Test(test_arbresFloat, test_rightRotate, .init = setup) {
	puts("Test de la fonction 'rightRotate'");
	nodeFloat* noeud = t9->son_l;
	cr_assert_float_eq(t9->value, 7.12, 0.000001);
	cr_assert_null(t9->parent);
	cr_assert_float_eq(noeud->value, 4.12, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t9->son_r;
	cr_assert_float_eq(noeud->value, 20.1, 0.000001);
	noeud = t9->son_r->son_l;
	cr_assert_float_eq(noeud->value, 17.1, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t9->son_r->son_r;
	cr_assert_float_eq(noeud->value, 51.1, 0.00001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);		
}

Test(test_arbresFloat, test_leftRotate, .init = setup) {
	puts("Test de la fonction 'leftRotate'");
	nodeFloat* t = leftRotateFloat(t9);
	nodeFloat* noeud = t->son_l;
	cr_assert_float_eq(t->value, 20.1, 0.000001);
	cr_assert_null(t->parent);
	cr_assert_float_eq(noeud->value, 7.12, 0.000001);
	noeud = t->son_l->son_l;
	cr_assert_float_eq(noeud->value, 4.12, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t->son_l->son_r;
	cr_assert_float_eq(noeud->value, 17.1, 0.000001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	
	noeud = t->son_r;
	cr_assert_float_eq(noeud->value, 51.1, 0.00001);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);		
}

Test(test_arbresFloat, test_AVL_add, .init = setup) {
	puts("Test de la fonction 'AVL_add'");
	nodeFloat* t = new_binary_tree_float(12.1);
	nodeFloat* temp = AVL_addFloat(t, 3.12);
	t = temp;
	temp = AVL_addFloat(t, 2.12);
	t = temp;
	temp = AVL_addFloat(t, 5.12);
	t = temp;
	temp = AVL_addFloat(t, 4.12);
	t = temp;
	temp = AVL_addFloat(t, 7.12);
	t = temp;
	temp = t->son_l;
	cr_assert_float_eq(t->value, 5.12, 0.000001);
	cr_assert_null(t->parent);
	cr_assert_float_eq(temp->value, 3.12, 0.000001);
	temp = t->son_l->son_l;
	cr_assert_float_eq(temp->value, 2.12, 0.000001);
	cr_assert_null(temp->son_l);
	cr_assert_null(temp->son_r);
	temp = t->son_l->son_r;
	cr_assert_float_eq(temp->value, 4.12, 0.000001);
	cr_assert_null(temp->son_l);
	cr_assert_null(temp->son_r);	
	temp = t->son_r;
	cr_assert_float_eq(temp->value, 12.1, 0.000001);
	cr_assert_null(temp->son_r);
	temp = t->son_r->son_l;
	cr_assert_float_eq(temp->value, 7.12, 0.000001);
	cr_assert_null(temp->son_l);
	cr_assert_null(temp->son_r);
}