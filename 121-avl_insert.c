#include "binary_trees.h"

/**
* search - searches for a value in a Binary Serach Tree
*
* @tree: pointer to the root node of the BST to search
* @value: value to search in the tree
*
* Return: pointer to the node containing a value equals to value
*/
bst_t *search(const bst_t *tree, int value)
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

/**
* insert - inserts a value inan AVL Tree
*
* @tree: pointer to the root node of the AVL tree
* @value: value to store in the node to be inserted
* @is_inserted: flag for insertion
*
* Return: pointer to the created node
*/
avl_t *insert(avl_t *tree, int value, int *is_inserted)
{
	int balance;

	if (tree == NULL)
		return (binary_tree_node(NULL, value));

	if (value > tree->n)
	{
		tree->right = insert(tree->right, value, is_inserted);
		tree->right->parent = tree;
	}
	else if (value < tree->n)
	{
		tree->left = insert(tree->left, value, is_inserted);
		tree->left->parent = tree;
	}
	else
	{
		*is_inserted = 0;
		return (tree);
	}

	balance = binary_tree_balance(tree);

	if (balance > 1 && value < tree->left->n)
		return (binary_tree_rotate_right(tree));
	if (balance < -1 && value > tree->right->n)
		return (binary_tree_rotate_left(tree));
	if (balance > 1 && value > tree->left->n)
	{
		tree->left = binary_tree_rotate_left(tree->left);
		return (binary_tree_rotate_right(tree));
	}
	if (balance < -1 && value < tree->right->n)
	{
		tree->right = binary_tree_rotate_right(tree->right);
		return (binary_tree_rotate_left(tree));
	}
	return (tree);
}

/**
* avl_insert - inserts a value inan AVL Tree
*
* @tree: address of pointet to the root node of the AVL tree
* @value: value to store in the node to be inserted
*
* Return: pointer to the created node
*/
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *tmp;
	int is_inserted = 1;

	if (tree == NULL)
		return (NULL);

	*tree = insert(*tree, value, &is_inserted);
	if (is_inserted)
		tmp = search(*tree, value);

	return (tmp);
}
