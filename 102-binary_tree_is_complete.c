#include "binary_trees.h"


/**
* _depth - measures the heght of a binary tree
*
* @tree: pointer to the root node of the tree to measure the depth
*
* Return: the depth of the tree
*/
int _depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
		return (0);
	while (tree)
	{
		tree = tree->left;
		depth++;
	}
	return (depth);
}
/**
* binary_tree_is_complete_helper - check if a binary tree is complete
*
* @tree: pointer to the root node of the tree to check
* @current_depth: current depth of traversing
* @target_depth: max depth so the tree is complete
* @used: mark that the target_depth has changed
*
* Return: 1 if tree is complete else 0
*/
int binary_tree_is_complete_helper(const binary_tree_t *tree,
				   int current_depth, int *target_depth, int *used)
{
	if (!tree)
	{
		if (!*used && current_depth < *target_depth)
		{
			*used = 1;
			--*target_depth;
		}
		return (current_depth == *target_depth);
	}

	return (binary_tree_is_complete_helper(tree->left, current_depth + 1,
					target_depth, used) &&
	binary_tree_is_complete_helper(tree->right, current_depth + 1,
				target_depth, used));
}
/**
* binary_tree_is_complete - check if a binary tree is complete
*
* @tree: pointer to the root node of the tree to check
*
* Return: 1 if tree is complete else 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int target_depth;
	int used = 0;

	if (tree == NULL)
		return (0);
	target_depth = _depth(tree);

	return (binary_tree_is_complete_helper(tree, 0, &target_depth, &used));
}
