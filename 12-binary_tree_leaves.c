#include "binary_trees.h"

/**
* binary_tree_leaves - measures size of binary tree
* 
* @tree: pointer to the root node of the tre to measure the size
*
* Return: count of leaves of the tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
  size_t count, left_count, right_count;

  if (tree == NULL)
    return (0);

  if (!tree->left && !tree->right)
    return (1);

  left_count = binary_tree_leaves(tree->left);
  right_count = binary_tree_leaves(tree->right);
  count = right_count + left_count;

  return (count);
}
