#include <stdlib.h>
#include <stdio.h>

#include "arbres.h"

node* new_binary_tree(int value) {
	node* tree = malloc(sizeof(node));
	tree->value = value;
	tree->son_l = NULL;
	tree->son_r = NULL;
	tree->parent = NULL;
	return tree;
}

node* makeRoot(node* subtree_l, int v, node* subtree_r) {
	if ((isEmpty(subtree_r) || v < least(subtree_r)) && (isEmpty(subtree_l) || v > greatest(subtree_l))) {
		node* root = new_binary_tree(v);
		root->son_l = subtree_l;
		root->son_r = subtree_r;
		return root;		
	} return NULL;
}

int isEmpty(node* binary_tree) {
	if (binary_tree == NULL) {
		return 1;
	} return 0;
}

int hasLeft(node* binary_tree) {
	if (isEmpty(binary_tree) || binary_tree->son_l == NULL) {
		return 0;
	} return 1;
}

int hasRight(node* binary_tree) {
	if (isEmpty(binary_tree) || binary_tree->son_r == NULL) {
		return 0;
	} return 1;	
}

int has(node* binary_tree, int v) {
	if (isEmpty(binary_tree)) {
		return 0;
	}
	if (binary_tree->parent == NULL) {
		if (v == binary_tree->value) {
			return 1;
		}
		if (v < binary_tree->value) {
			has(binary_tree->son_l, v);
		}
		if (v > binary_tree->value) {
			has(binary_tree->son_r, v);
		}		
	}
	if (binary_tree->parent != NULL) {
		node* root = NULL;
		while (root->parent != NULL) {
			root = root->parent;
		}	
		if (v == root->value) {
			return 1;
		}
		if (v < root->value) {
			has(binary_tree->son_l, v);
		}
		if (v > root->value) {
			has(binary_tree->son_r, v);
		}				
	} return 0;
}

int value(node* binary_tree) {
	return binary_tree->value;
}

node* left(node* binary_tree) {
	return binary_tree->son_l;
}

node* right(node* binary_tree) {
	return binary_tree->son_r;
}

int least(node* binary_tree) {
	if (isEmpty(binary_tree)) {
		return 0;
	} else if (hasLeft(binary_tree)) {
		return least(binary_tree->son_l);
	} else {
		return binary_tree->value;
	}
}

int greatest(node* binary_tree) {
	if (isEmpty(binary_tree)) {
		return 0;
	} else if (hasRight(binary_tree)) {
		return greatest(binary_tree->son_r);
	} else {
		return binary_tree->value;
	}
}

node* cpy(node* bst) {
	if (isEmpty(bst)) {
		return NULL;
	} 
	if (!hasLeft(bst) && !hasRight(bst)) {
		return new_binary_tree(bst->value);
	}
	node* t = new_binary_tree(bst->value);
	t->son_l = cpy(bst->son_l);
	t->son_r = cpy(bst->son_r);
	return t;
}

node* add(node* binary_tree, int v) {
	node* t = cpy(binary_tree);
	if (has(t, v)) {
		return t;
	}
	if (isEmpty(t)) {
		t = new_binary_tree(v);
		return t;
	}
	if (v > t->value) {
		t->son_r = add(t->son_r, v);
	}
	if (v < t->value) {
		t->son_l = add(t->son_l, v);
	} return t;
}

int height(node* binary_tree) {
	if (isEmpty(binary_tree)) {
		return 0;
	} else {
		int height_l = height(binary_tree->son_l);
		int height_r = height(binary_tree->son_r);

		if (height_l > height_r) {
			return 1 + height_l;
		} return 1 + height_r;
	}
}

void print_ordered_bst(node* binary_tree) {
	if (isEmpty(binary_tree)) {
		printf("");
	} else if (!hasLeft(binary_tree) && !hasRight(binary_tree)) {
		printf("%d\n", binary_tree->value);
	} else {
		print_ordered_bst(binary_tree->son_l);
		printf("%d\n", binary_tree->value);
		print_ordered_bst(binary_tree->son_r);
	}
}

int balance(node* binary_tree) {
	if (isEmpty(binary_tree)) {
		return 0;
	} else {
		return height(binary_tree->son_l) - height(binary_tree->son_r);
	}
}

node* rightRotate(node* binary_tree) {
	if (isEmpty(binary_tree) || !hasLeft(binary_tree)) {
		return binary_tree;
	} else {
		return makeRoot(left(binary_tree->son_l), value(binary_tree->son_l), makeRoot(right(binary_tree->son_l), binary_tree->value, binary_tree->son_r));
	}
}

node* leftRotate(node* binary_tree) {
	if (isEmpty(binary_tree) || !hasRight(binary_tree)) {
		return binary_tree;
	} else {
		return makeRoot(makeRoot(binary_tree->son_l, binary_tree->value, left(binary_tree->son_r)), value(binary_tree->son_r), right(binary_tree->son_r));
	}
}

node* balancing(node* binary_tree) {
	if (isEmpty(binary_tree)) {
		return binary_tree;
	}
	binary_tree->son_l = balancing(binary_tree->son_l);
	binary_tree->son_r = balancing(binary_tree->son_r);
	if (balance(binary_tree) == 2) {
		if (balance(binary_tree->son_l) == -1) {
			binary_tree->son_l = leftRotate(binary_tree->son_l);
		}
		return rightRotate(binary_tree);
	} else if (balance(binary_tree) == -2) {
		if (balance(binary_tree->son_r) == 1) {
			binary_tree->son_r = rightRotate(binary_tree->son_r);
		}
		return leftRotate(binary_tree);
	} return binary_tree;
}

node* AVL_add(node* binary_tree, int v) {
	binary_tree = add(binary_tree, v);
	return balancing(binary_tree);
}