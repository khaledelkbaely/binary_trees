#include "binary_trees.h"

/**
* binary_tree_is_full - measures size of binary tree
*
* @tree: pointer to the root node of the tre to measure the size
*
* Return: size of the tree
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->right)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return ((!left || !right) ? 0 : 1);
	}
	else if (!tree->left && !tree->right)
		return (1);
	return (0);
}
