#include "binary_trees.h"

/**
* is_perfect - measures size of binary tree
* 
* @tree: pointer to the root node of the tre to measure the size
*
* Return: size of the tree
*/
int is_perfect(const binary_tree_t *tree)
{
  int left = 0, right = 0;
  if (tree == NULL)
    return (0);

  if (tree->left && tree->right)
  {
    left = 1 + is_perfect(tree->left);
    right = 1 + is_perfect(tree->right);
    if (right == left && right && left)
      return (right);
    return (0);
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
  if (tree == NULL)
    return (0);
  return (is_perfect(tree) ? 1 : 0);
}
