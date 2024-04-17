#include "binary_trees.h"

/**
* bst_search - searches for a value in a Binary Serach Tree
*
* @tree: pointer to the root node of the BST to search
* @value: value to search in the tree
*
* Return: pointer to the node containing a value equals to value
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	tmp = (bst_t *)tree;
	while (tmp)
	{
		if (tmp->n > value)
			tmp = tmp->left;
		else if (tmp->n < value)
			tmp = tmp->right;
		else
			return (tmp);
	}
	return (NULL);
}
