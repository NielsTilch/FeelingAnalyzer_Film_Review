#include <criterion/criterion.h>

#include "./../src/arbres.h"

node* t0;
node* t1;
node* t2;
node* t3;
node* t4;
node* t5;
node* t6;
node* t7;
node* t8;
node* t9;

void setup(void) {
	t0 = NULL;
	t1 = new_binary_tree(12);
	t2 = new_binary_tree(5);
	t3 = add(t2, 10);
	t4 = new_binary_tree(20);
	t5 = add(t4, 7);
	t6 = add(t5, 51);
	t7 = add(t6, 4);
	t8 = add(t7, 17);
	t9 = rightRotate(t8);	
}

void teardown(void) {
}

Test(test_arbres, test_creer, .init = setup) {
	puts("Test de la fonction 'new_binary_tree'");
	cr_assert_eq(t1->value, 12);
	cr_assert_null(t1->son_l);
	cr_assert_null(t1->son_r);
	cr_assert_null(t1->parent);
}

Test(test_arbres, test_isEmpty, .init = setup) {
	puts("Test de la fonction 'isEmpty'");
	cr_assert_eq(isEmpty(t0), 1);
	cr_assert_eq(isEmpty(t1), 0);
}

Test(test_arbres, test_least, .init = setup) {
	puts("Test de la fonction 'least'");
	cr_assert_eq(least(t0), 0);
	cr_assert_eq(least(t1), 12);
	cr_assert_eq(least(t3), 5);
	cr_assert_eq(least(t8), 4);
}

Test(test_arbres, test_greatest, .init = setup) {
	puts("Test de la fonction 'greatest'");
	cr_assert_eq(greatest(t0), 0);
	cr_assert_eq(greatest(t1), 12);
	cr_assert_eq(greatest(t3), 10);
	cr_assert_eq(greatest(t8), 51);
}

Test(test_arbres, test_makeRoot, .init = setup) {
	puts("Test de la fonction 'makeRoot'"); 
	node* t = makeRoot(t0, 2, t0);
	cr_assert_eq(t->value, 2);
	cr_assert_null(t->son_l);
	cr_assert_null(t->son_r);
	cr_assert_null(t->parent);

	t = makeRoot(t1, 21, t0);
	node* noeud = t->son_l;
	cr_assert_eq(t->value, 21);
	cr_assert_null(t->parent);
	cr_assert_null(t->son_r);
	cr_assert_eq(noeud->value, 12);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);

	t = makeRoot(t0, 10, t1);
	noeud = t->son_r;
	cr_assert_eq(t->value, 10);
	cr_assert_null(t->parent);
	cr_assert_null(t->son_l);
	cr_assert_eq(noeud->value, 12);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	

	t = makeRoot(t2, 7, t1);
	noeud = t->son_l;
	cr_assert_eq(t->value, 7);
	cr_assert_null(t->parent);
	cr_assert_eq(noeud->value, 5);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	
	noeud = t->son_r;
	cr_assert_eq(noeud->value, 12);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
}

Test(test_arbres, test_hasLeft, .init = setup) {
	puts("Test de la fonction 'hasLeft'");
	cr_assert_eq(hasLeft(t0), 0);
	cr_assert_eq(hasLeft(t1), 0);
	cr_assert_eq(hasLeft(t3), 0);
	cr_assert_eq(hasLeft(t5), 1);
	cr_assert_eq(hasLeft(t8), 1);
}

Test(test_arbres, test_hasRight, .init = setup) {
	puts("Test de la fonction 'hasRight'");
	cr_assert_eq(hasRight(t0), 0);
	cr_assert_eq(hasRight(t1), 0);
	cr_assert_eq(hasRight(t3), 1);
	cr_assert_eq(hasRight(t5), 0);
	cr_assert_eq(hasRight(t8), 1);
}

Test(test_arbres, test_has, .init = setup) {
	puts("Test de la fonction 'has'");
	cr_assert_eq(has(t0, 2), 0);
	cr_assert_eq(has(t1, 12), 1);
	cr_assert_eq(has(t3, 5), 1);
	cr_assert_eq(has(t8, 1), 0);
}

Test(test_arbres, test_add, .init = setup) {
	puts("Test de la fonction 'add'");
	node* noeud = t5->son_l;
	cr_assert_eq(t5->value, 20);
	cr_assert_null(t5->parent);
	cr_assert_null(t5->son_r);
	cr_assert_eq(noeud->value, 7);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);

	noeud = t3->son_r;
	cr_assert_eq(t3->value, 5);
	cr_assert_null(t3->parent);
	cr_assert_null(t3->son_l);
	cr_assert_eq(noeud->value, 10);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	

	noeud = t6->son_l;
	cr_assert_eq(t6->value, 20);
	cr_assert_null(t6->parent);
	cr_assert_eq(noeud->value, 7);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t6->son_r;
	cr_assert_eq(noeud->value, 51);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	
}

Test(test_arbres, test_height, .init = setup) {
	puts("Test de la fonction 'height'");
	cr_assert_eq(height(t0), 0);
	cr_assert_eq(height(t1), 1);
	cr_assert_eq(height(t3), 2);
	cr_assert_eq(height(t6), 2);
	cr_assert_eq(height(t8), 3);
}

Test(test_arbres, test_balance, .init = setup) {
	puts("Test de la fonction 'balance'");
	cr_assert_eq(balance(t0), 0);
	cr_assert_eq(balance(t1), 0);
	cr_assert_eq(balance(t3), -1);
	cr_assert_eq(balance(t5), 1);
	cr_assert_eq(balance(t6), 0);
	cr_assert_eq(balance(t8), 1);
}

Test(test_arbres, test_rightRotate, .init = setup) {
	puts("Test de la fonction 'rightRotate'");
	node* noeud = t9->son_l;
	cr_assert_eq(t9->value, 7);
	cr_assert_null(t9->parent);
	cr_assert_eq(noeud->value, 4);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t9->son_r;
	cr_assert_eq(noeud->value, 20);
	noeud = t9->son_r->son_l;
	cr_assert_eq(noeud->value, 17);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t9->son_r->son_r;
	cr_assert_eq(noeud->value, 51);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);		
}

Test(test_arbres, test_leftRotate, .init = setup) {
	puts("Test de la fonction 'leftRotate'");
	node* t = leftRotate(t9);
	node* noeud = t->son_l;
	cr_assert_eq(t->value, 20);
	cr_assert_null(t->parent);
	cr_assert_eq(noeud->value, 7);
	noeud = t->son_l->son_l;
	cr_assert_eq(noeud->value, 4);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);
	noeud = t->son_l->son_r;
	cr_assert_eq(noeud->value, 17);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);	
	noeud = t->son_r;
	cr_assert_eq(noeud->value, 51);
	cr_assert_null(noeud->son_l);
	cr_assert_null(noeud->son_r);		
}

Test(test_arbres, test_AVL_add, .init = setup) {
	puts("Test de la fonction 'AVL_add'");
	node* t = new_binary_tree(12);
	node* temp = AVL_add(t, 3);
	t = temp;
	temp = AVL_add(t, 2);
	t = temp;
	temp = AVL_add(t, 5);
	t = temp;
	temp = AVL_add(t, 4);
	t = temp;
	temp = AVL_add(t, 7);
	t = temp;
	temp = t->son_l;
	cr_assert_eq(t->value, 5);
	cr_assert_null(t->parent);
	cr_assert_eq(temp->value, 3);
	temp = t->son_l->son_l;
	cr_assert_eq(temp->value, 2);
	cr_assert_null(temp->son_l);
	cr_assert_null(temp->son_r);
	temp = t->son_l->son_r;
	cr_assert_eq(temp->value, 4);
	cr_assert_null(temp->son_l);
	cr_assert_null(temp->son_r);	
	temp = t->son_r;
	cr_assert_eq(temp->value, 12);
	cr_assert_null(temp->son_r);
	temp = t->son_r->son_l;
	cr_assert_eq(temp->value, 7);
	cr_assert_null(temp->son_l);
	cr_assert_null(temp->son_r);
}