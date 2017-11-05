#include<stdlib.h>
#include<stdio.h>

typedef struct bin_tree {
	int data;
	struct bin_tree *left, *right;
} tnode;

void insert (tnode **leaf, int val)
{
	if (!(*leaf))
	{
		(*leaf) = (tnode *)malloc(sizeof tnode);
		(*leaf)->data = val;
		(*leaf)->left = (*leaf)->right = NULL;
	}
	else if (val < (*leaf)->data)
	{
		insert(&(*leaf)->left, val);
	}
	else if (val > (*leaf)->data)
	{
		insert(&(*leaf)->right, val);
	}
}

tnode *search (tnode *root, val)
{
	if (!root) return NULL;
	if (val == root->data) return root;
	if (val < root->data) return search(root->left, val);
	if (val > root->data) return search(root->right, val);
}

void destroy_tree (tnode *root)
{
	if (root)
	{
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root);
	}
}
