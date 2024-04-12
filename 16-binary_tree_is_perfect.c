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

		height_left = (tree->left ? 1 + _height(tree->left) : 0);
		height_right = (tree->right ? 1 + _height(tree->right) : 0);

		return (height_left > height_right ? height_left : height_right);
}
/**
* is_full - measures size of binary tree
* 
* @tree: pointer to the root node of the tre to measure the size
*
* Return: size of the tree
*/
int is_full(const binary_tree_t *tree)
{
  int left, right;
  if (tree == NULL)
    return (0);

  if (tree->left && tree->right)
  {
    left = is_full(tree->left);
    right = is_full(tree->right);
    return (!left || !right) ? 0 : 1;
  }
  else if (!tree->left && !tree->right)
    return (1);
  return (0);
}

/**
* binary_tree_is_perfect - measures size of binary tree
* 
* @tree: pointer to the root node of the tre to measure the size
*
* Return: size of the tree
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
  size_t height_left, height_right;

  if (tree == NULL)
    return (0);

  height_left = _height(tree->left);
  height_right = _height(tree->right);
  if (is_full(tree) && height_left == height_right && height_right && height_left)
    return (1);
  return (0);
}
