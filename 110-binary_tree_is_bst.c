#include "binary_trees.h"

/**
 * is_valid_bst - binary_tree_is_bst helper
 *
 * @root: current root
 * @low: low node
 * @high: high node
 *
 * Return: 1 if bst else 0
 */
int is_valid_bst(binary_tree_t *root, binary_tree_t *low, binary_tree_t *high)
{
	if (root == NULL)
	return (1);

	if ((low && low->n >= root->n) || (high && high->n <= root->n))
		return (0);

	return (is_valid_bst(root->left, low, root) &&
		is_valid_bst(root->right, root, high));
}

/**
* binary_tree_is_bst - check if a binary tree is a valid BST
*
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid BST and 0 otherwise
*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_valid_bst((binary_tree_t *)tree, NULL, NULL));
}
