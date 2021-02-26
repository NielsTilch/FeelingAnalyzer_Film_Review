#ifndef arbres_float_h
#define arbres_float_h

typedef struct nodeFloat {
	float value;
	struct nodeFloat* son_l;
	struct nodeFloat* son_r;
	struct nodeFloat* parent;
} nodeFloat;

/* Create an empty tree*/
nodeFloat* new_binary_tree_float(float value);

/* Construct a tree with v as the root */
nodeFloat* makeRootFloat(nodeFloat* subtree_l, float v, nodeFloat* subtree_r);

/* Return 1 if the tree is empty */
int isEmptyFloat(nodeFloat* binary_tree);

/* Return 1 if the tree has a left subtree */
int hasLeftFloat(nodeFloat* binary_tree);

/* Return 1 if the tree has a right subtree */
int hasRightFloat(nodeFloat* binary_tree);

/* Return 1 if the value is in the tree */
int hasFloat(nodeFloat* binary_tree, float v);

/* Return the value of the node */
float valueFloat(nodeFloat* binary_tree);

/* Return the left subtree */
nodeFloat* leftFloat(nodeFloat* binary_tree);

/* Return the right subtree */
nodeFloat* rightFloat(nodeFloat* binary_tree);

/* Return the minimum value of the tree */
float leastFloat(nodeFloat* binary_tree);

/* Return the maximum value of the tree */
float greatestFloat(nodeFloat* binary_tree);

/* Return a copy of the tree */
nodeFloat* cpyFloat(nodeFloat* bst);

/* Add a value in a BST */
nodeFloat* addFloat(nodeFloat* binary_tree, float v);

/* Return the height of a binary tree */
int heightFloat(nodeFloat* binary_tree);

/* Print the sorted values of a BST in an increasing order */
void print_ordered_bst_float(nodeFloat* binary_tree);

/* Return the balance of a BST */
int balanceFloat(nodeFloat* binary_tree);

/* Return the tree gotten by right rotation */
nodeFloat* rightRotateFloat(nodeFloat* binary_tree);

/* Return the tree gotten by left rotation */
nodeFloat* leftRotateFloat(nodeFloat* binary_tree);

/* Return a balanced tree */
nodeFloat* balancingFloat(nodeFloat* binary_tree);

/* Add a node while maintaining the AVL property */
nodeFloat* AVL_addFloat(nodeFloat* binary_tree, float v);

#endif