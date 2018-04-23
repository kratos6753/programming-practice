#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

int main() {
	TNode *root = create_new_tnode(1);
	root->left = create_new_tnode(2);
	root->right = create_new_tnode(3);
	root->left->left = create_new_tnode(4);
	root->left->right = create_new_tnode(5);
	root->right->left = create_new_tnode(6);
	root->right->right = create_new_tnode(7);
	root->right->left->right = create_new_tnode(8);
	root->right->right->right = create_new_tnode(9);
	printf("Top View\n");
	print_tree_top_view(root);
	printf("\n");
	printf("Bottom View\n");
	print_tree_bottom_view(root);
	printf("\n");
	return 0;
}
