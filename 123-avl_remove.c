#include "binary_trees.h"
#include <stdlib.h>

/**
* min_node - find min node
*
* @root: pointer to tree
*
* Return: pointer to the min node
*/
avl_t *min_node(avl_t *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

/**
* balance - balance given node
*
* @tree: node to balance
*
* Return: pointer to node
*/
avl_t *balance(avl_t *tree)
{
	int balance = binary_tree_balance(tree);

	if (balance > 1 && binary_tree_balance(tree->left) >= 0)
		return (binary_tree_rotate_right(tree));
	if (balance < -1 && binary_tree_balance(tree->right) <= 0)
		return (binary_tree_rotate_left(tree));
	if (balance > 1 && binary_tree_balance(tree->left) < 0)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && binary_tree_balance(tree->right) > 0)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}

	return (tree);
}

/**
* avl_remove - removes a node from a Binary Search Tree
*
* @root: pointer to the root node of the tre where you will remove a node
* @value: value to remove in the tree
*
* Return: a pointer to the new root node of the tree after removing
* the desired value
*/
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp;

	if (!root)
		return (NULL);

	if (value > root->n)
		root->right = avl_remove(root->right, value);
	else if (value < root->n)
		root->left = avl_remove(root->left, value);
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
			root->right = avl_remove(root->right, tmp->n);
		}
	}

	if (root == NULL)
		return (root);

	return (balance(root));
}

