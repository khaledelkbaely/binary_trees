#include "binary_trees.h"

/**
 * binary_tree_depth - measures the heght of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: the depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
		const binary_tree_t *ptr;
		size_t depth = 0;

		if (tree == NULL)
				return (0);

		ptr = tree;
		while (ptr->parent)
		{
				depth++;
				ptr = ptr->parent;
		}
		return (depth);
}
