#include "binary_trees.h"

/**
* binary_tree_size - measures size of binary tree
* 
* @tree: pointer to the root node of the tre to measure the size
*
* Return: size of the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
  size_t size, left_size, right_size;
  size = left_size = right_size = 0;

  if (tree == NULL)
    return (0)

  left_size = binary_tree_size(tree->left);
  right_size = binary_tree_size(tree->right);
  size = left_size + right_size + 1;

  return (size);
}
