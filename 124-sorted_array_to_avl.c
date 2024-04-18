#include "binary_trees.h"

/**
* insert - insert to sorted array
*
* @tree: pointer to current root
* @parent: pointer to the parent of current root
* @array: array of sorted values
* @start: current start of the array
* @end: current end of the array
*
* Return: pointer the new created tree
*/
avl_t *insert(avl_t *tree, avl_t *parent, int *array, int start, int end)
{
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	tree = binary_tree_node(parent, array[mid]);
	tree->right = insert(tree->right, tree, array, mid + 1, end);
	tree->left = insert(tree->left, tree, array, start, mid - 1);
	return (tree);
}

/**
* sorted_array_to_avl - builds an AVL tree from an array
*
* @array: pointer to the first element of the array to be converted
* @size: number of element in teh array
*
* Return: pointer to the root node of the created AVL tree or NULL on failling
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || !size)
		return (NULL);
	tree = NULL;
	tree = insert(tree, NULL, array, 0, size - 1);

	return (tree);
}
