#include "binary_trees.h"

/**
* bst_insert - inserts a value in a Binary Search Tree
*
* @tree: double pointer to the root node of the BST to inert hte value
* @value: value to store in the node to be inserted
*
* Return: pointer to the created node or NULL on failling
*/
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tmp;
	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		new = binary_tree_node(*tree, value);
		*tree = new;
	}
	else
	{
		tmp = *tree;
		if (value > tmp->n)
		{
			if (tmp->right)
				new = bst_insert(&tmp->right, value);
			else
			{
				tmp->right = binary_tree_node(tmp, value);
				new = tmp->right;
			}
		}
		else if (value < tmp->n)
		{
			if (tmp->left)
				new = bst_insert(&tmp->left, value);
			else
			{
				tmp->left = binary_tree_node(tmp, value);
				new = tmp->left;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
