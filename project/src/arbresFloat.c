#include <stdlib.h>
#include <stdio.h>

#include "arbresFloat.h"

nodeFloat* new_binary_tree_float(float value) {
	nodeFloat* tree = malloc(sizeof(nodeFloat));
	tree->value = value;
	tree->son_l = NULL;
	tree->son_r = NULL;
	tree->parent = NULL;
	return tree;
}

nodeFloat* makeRootFloat(nodeFloat* subtree_l, float v, nodeFloat* subtree_r) {
	if ((isEmptyFloat(subtree_r) || v < leastFloat(subtree_r)) && (isEmptyFloat(subtree_l) || v > greatestFloat(subtree_l))) {
		nodeFloat* root = new_binary_tree_float(v);
		root->son_l = subtree_l;
		root->son_r = subtree_r;
		return root;		
	} return NULL;
}

int isEmptyFloat(nodeFloat* binary_tree) {
	if (binary_tree == NULL) {
		return 1;
	} return 0;
}

int hasLeftFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree) || binary_tree->son_l == NULL) {
		return 0;
	} return 1;
}

int hasRightFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree) || binary_tree->son_r == NULL) {
		return 0;
	} return 1;	
}

int hasFloat(nodeFloat* binary_tree, float v) {
	if (isEmptyFloat(binary_tree)) {
		return 0;
	}
	if (binary_tree->parent == NULL) {
		if (v == binary_tree->value) {
			return 1;
		}
		if (v < binary_tree->value) {
			hasFloat(binary_tree->son_l, v);
		}
		if (v > binary_tree->value) {
			hasFloat(binary_tree->son_r, v);
		}		
	}
	if (binary_tree->parent != NULL) {
		nodeFloat* root = NULL;
		while (root->parent != NULL) {
			root = root->parent;
		}	
		if (v == root->value) {
			return 1;
		}
		if (v < root->value) {
			hasFloat(binary_tree->son_l, v);
		}
		if (v > root->value) {
			hasFloat(binary_tree->son_r, v);
		}				
	} return 0;
}

float valueFloat(nodeFloat* binary_tree) {
	return binary_tree->value;
}

nodeFloat* leftFloat(nodeFloat* binary_tree) {
	return binary_tree->son_l;
}

nodeFloat* rightFloat(nodeFloat* binary_tree) {
	return binary_tree->son_r;
}

float leastFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree)) {
		return 0;
	} else if (hasLeftFloat(binary_tree)) {
		return leastFloat(binary_tree->son_l);
	} else {
		return binary_tree->value;
	}
}

float greatestFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree)) {
		return 0;
	} else if (hasRightFloat(binary_tree)) {
		return greatestFloat(binary_tree->son_r);
	} else {
		return binary_tree->value;
	}
}

nodeFloat* cpyFloat(nodeFloat* bst) {
	if (isEmptyFloat(bst)) {
		return NULL;
	} 
	if (!hasLeftFloat(bst) && !hasRightFloat(bst)) {
		return new_binary_tree_float(bst->value);
	}
	nodeFloat* t = new_binary_tree_float(bst->value);
	t->son_l = cpyFloat(bst->son_l);
	t->son_r = cpyFloat(bst->son_r);
	return t;
}

nodeFloat* addFloat(nodeFloat* binary_tree, float v) {
	nodeFloat* t = cpyFloat(binary_tree);
	if (hasFloat(t, v)) {
		return t;
	}
	if (isEmptyFloat(t)) {
		t = new_binary_tree_float(v);
		return t;
	}
	if (v > t->value) {
		t->son_r = addFloat(t->son_r, v);
	}
	if (v < t->value) {
		t->son_l = addFloat(t->son_l, v);
	} return t;
}

int heightFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree)) {
		return 0;
	} else {
		int height_l = heightFloat(binary_tree->son_l);
		int height_r = heightFloat(binary_tree->son_r);
		if (height_l > height_r) {
			return 1 + height_l;
		} return 1 + height_r;
	}
}

void print_ordered_bst_float(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree)) {
		printf("");
	} else if (!hasLeftFloat(binary_tree) && !hasRightFloat(binary_tree)) {
		printf("%f\n", binary_tree->value);
	} else {
		print_ordered_bst_float(binary_tree->son_l);
		printf("%f\n", binary_tree->value);
		print_ordered_bst_float(binary_tree->son_r);
	}
}

int balanceFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree)) {
		return 0;
	} else {
		return heightFloat(binary_tree->son_l) - heightFloat(binary_tree->son_r);
	}
}

nodeFloat* rightRotateFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree) || !hasLeftFloat(binary_tree)) {
		return binary_tree;
	} else {
		return makeRootFloat(leftFloat(binary_tree->son_l), valueFloat(binary_tree->son_l), makeRootFloat(rightFloat(binary_tree->son_l), binary_tree->value, binary_tree->son_r));
	}
}

nodeFloat* leftRotateFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree) || !hasRightFloat(binary_tree)) {
		return binary_tree;
	} else {
		return makeRootFloat(makeRootFloat(binary_tree->son_l, binary_tree->value, leftFloat(binary_tree->son_r)), valueFloat(binary_tree->son_r), rightFloat(binary_tree->son_r));
	}
}

nodeFloat* balancingFloat(nodeFloat* binary_tree) {
	if (isEmptyFloat(binary_tree)) {
		return binary_tree;
	}
	binary_tree->son_l = balancingFloat(binary_tree->son_l);
	binary_tree->son_r = balancingFloat(binary_tree->son_r);
	if (balanceFloat(binary_tree) == 2) {
		if (balanceFloat(binary_tree->son_l) == -1) {
			binary_tree->son_l = leftRotateFloat(binary_tree->son_l);
		}
		return rightRotateFloat(binary_tree);
	} else if (balanceFloat(binary_tree) == -2) {
		if (balanceFloat(binary_tree->son_r) == 1) {
			binary_tree->son_r = rightRotateFloat(binary_tree->son_r);
		}
		return leftRotateFloat(binary_tree);
	} return binary_tree;
}

nodeFloat* AVL_addFloat(nodeFloat* binary_tree, float v) {
	binary_tree = addFloat(binary_tree, v);
	return balancingFloat(binary_tree);
}