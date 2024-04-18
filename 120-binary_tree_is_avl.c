#include "binary_trees.h"


/**
* _height - measures the heght of a binary tree
*
* @tree: pointer to the root node of the tree to measure the height
*
* Return: the height of the tree
*/
size_t _height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = (tree->left ? 1 + _height(tree->left) : 1);
	height_right = (tree->right ? 1 + _height(tree->right) : 1);

	return (height_left > height_right ? height_left : height_right);
}

/**
* tree_balance - measures size of binary tree
*
* @tree: pointer to the root node of the tre to measure the size
*
* Return: count of nodes of the tree
*/
int tree_balance(const binary_tree_t *tree)
{
	int total, height_left, height_right;

	total = height_right = height_left = 0;

	if (tree == NULL)
		return (0);


	height_left = (int) _height(tree->left);
	height_right = (int) _height(tree->right);
	total = height_left - height_right;
	if (total < 0)
		total = -total;

	return (total);
}

/**
 * is_avl - check if binary tree is AVL Tree
 *
 * @root: pointer to root
 * @low: pointer to the lowest value node
 * @high: pointer to the highest value node
 *
 * Return: 1 if tree is valid AVL Tree
 */
int is_avl(binary_tree_t *root, binary_tree_t *low, binary_tree_t *high)
{
	if (!root)
		return (1);

	if ((low && root->n < low->n) ||
	    (high && root->n > high->n) ||
	    (tree_balance(root) > 1))
		return (0);

	return (is_avl(root->right, root, high) && is_avl(root->left, low, root));
}

/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
*
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is a valid AVL Tree else 0
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl((binary_tree_t *)tree, NULL, NULL));
}
