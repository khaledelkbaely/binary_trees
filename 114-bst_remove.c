#include "binary_trees.h"
#include <stdlib.h>

/**
* min_node - find min node
*
* @root: pointer to tree
*
* Return: pointer to the min node
*/
bst_t *min_node(bst_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

/**
* bst_remove - removes a node from a Binary Search Tree
*
* @root: pointer to the root node of the tre where you will remove a node
* @value: value to remove in the tree
*
* Return: a pointer to the new root node of the tree after removing
* the desired value
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);

	if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			root = root->right;
			root->parent = tmp->parent;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			root = root->left;
			root->parent = tmp->parent;
			free(tmp);
		}
		else
		{
			tmp = min_node(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}

	return (root);
}
