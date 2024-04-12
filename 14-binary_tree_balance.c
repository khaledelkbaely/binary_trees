#include "binary_trees.h"
#include <stdio.h>

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
* binary_tree_balance - measures size of binary tree
* 
* @tree: pointer to the root node of the tre to measure the size
*
* Return: count of nodes of the tree
*/
int binary_tree_balance(const binary_tree_t *tree)
{
  int total, height_left, height_right;
  total = height_right = height_left = 0;

  if (tree == NULL)
    return (0);


  height_left = (int) _height(tree->left);
  height_right = (int) _height(tree->right);
  total = height_left - height_right;

  return (total);
}
