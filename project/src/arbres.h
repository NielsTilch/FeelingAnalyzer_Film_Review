#ifndef arbres_h
#define arbres_h

typedef struct node {
	int value;
	struct node* son_l;
	struct node* son_r;
	struct node* parent;
} node;

/* Create an empty tree*/
node* new_binary_tree(int value);

/* Construct a tree with v as the root */
node* makeRoot(node* subtree_l, int v, node* subtree_r);

/* Return 1 if the tree is empty */
int isEmpty(node* binary_tree);

/* Return 1 if the tree has a left subtree */
int hasLeft(node* binary_tree);

/* Return 1 if the tree has a right subtree */
int hasRight(node* binary_tree);

/* Return 1 if the value is in the tree */
int has(node* binary_tree, int v);

/* Return the value of the node */
int value(node* binary_tree);

/* Return the left subtree */
node* left(node* binary_tree);

/* Return the right subtree */
node* right(node* binary_tree);

/* Return the minimum value of the tree */
int least(node* binary_tree);

/* Return the maximum value of the tree */
int greatest(node* binary_tree);

/* Return a copy of the tree */
node* cpy(node* bst);

/* Add a value in a BST */
node* add(node* binary_tree, int v);

/* Return the height of a binary tree */
int height(node* binary_tree);

/* Print the sorted values of a BST in an increasing order */
void print_ordered_bst(node* binary_tree);

/* Return the balance of a BST */
int balance(node* binary_tree);

/* Return the tree gotten by right rotation */
node* rightRotate(node* binary_tree);

/* Return the tree gotten by left rotation */
node* leftRotate(node* binary_tree);

/* Return a balanced tree */
node* balancing(node* binary_tree);

/* Add a node while maintaining the AVL property */
node* AVL_add(node* binary_tree, int v);

#endif
