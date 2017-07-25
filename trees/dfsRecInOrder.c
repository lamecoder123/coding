/*
 * dfsRecInOrder.c
 * using In Order Traversal
 * left -> root -> right
 *
 *   Author: Sandesh
 */
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 
 void dfsRecInOrder(node *root) {
 	if (!root)
		return;
	dfsRecInOrder(root->left);
	printf("%d ", root->data);
	dfsRecInOrder(root->right);
 }
 
