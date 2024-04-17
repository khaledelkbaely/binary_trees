#include "binary_trees.h"

/**
* array_to_bst - builds a Binary Search Tree from an array
*
* @array: pointer to the first element of the array to be converted
* @size: number of element in the array
*
* Return: pointer to the root node of the created BST
*/
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	int i;

	tree = NULL;
	if (size == 0 || !array)
		return (NULL);
	for (i = 0; i < (int)size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}
