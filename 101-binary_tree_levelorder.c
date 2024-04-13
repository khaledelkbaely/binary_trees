#include "binary_trees.h"
#include <stdlib.h>

/**
* _height - get height of the tree
*
* @tree: pointer to the root
*
* Return: height of the tree
*/
size_t _height(binary_tree_t *tree)
{
	size_t l, r;

	if (tree == NULL)
		return (0);
	l = _height(tree->left);
	r = _height(tree->right);

	return (l > r ? l + 1 : r + 1);
}

/**
 * current_level - process nodes at current level
 *
 * @node: pointer to the current node
 * @func: pointer to a function to call for each node
 * @l: current level
 *
 * Return: Nothing
 */
void current_level(const binary_tree_t *node, void (*func)(int), int l)
{
	if (node == NULL)
		return;

	if (l == 0)
		func(node->n);
	else if (l > 0)
	{
		current_level(node->left, func, l - 1);
		current_level(node->right, func, l - 1);
	}
}

/**
* binary_tree_levelorder - goes through a binary tree using
*			   level-order traversal
*
* @tree: pointer to the root node of the tree to traverse
* @func: pointer to a function to call for each node
*
* Return: Nothing
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h;
	int i;

	h = _height((binary_tree_t *)tree);

	for (i = 0; i < (int) h; i++)
		current_level(tree, func, i);
}
